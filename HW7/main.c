#include <stdio.h>
#include <stdlib.h>
#include <string.h>

union Person // to define Person union.
{
    char name[100];
    char address[100];
    int phone;
};

union Loan // to define Loan union.
{
    float arr[3];
};

struct BankAccount // to define BankAccount struct.
{
    union Person Customer;
    union Loan loans[3];
};

int counter = 1; // to define some global variables.
float base;

void listCustomers(int n, union Person *person) // to define listCustomers function.
{
    /*
     *This function prints customer names which are in person union.
     *
     *Returns nothing because type of void.
     */
    int i;
    for (i = 0; i < (n - 1); i++) // to list all customers' names with for loop.
    {
        printf("Customer ID = %d\n", i + 1);
        printf("Customer Name = %s\n\n", person[i].name);
    }
}
float loanarr[1000][3] = {0};
int loanperiod[1000][1];
void addCustomer(struct BankAccount *accounts, union Person *person) // to define addCustomer function.
{
    /*
     *This function gets user inputs for the new customers name,ID,phone and address and
     *  then it stores this inputs in struct and customers.txt file.
     *
     *Returns nothing because type of void.
     */

    int id;

    FILE *fptr = fopen("customers.txt", "a+"); // to create and open customers.txt file for writing.

    printf("Please Enter the Customer ID : "); // to get user input for customer ID.
    scanf("%d", &id);
    printf("Please Enter the Customer Phone : "); // to get user input for customer phone.
    scanf("%d", &person[counter - 1].phone);
    accounts[counter - 1].Customer.phone = person[counter - 1].phone;
    fprintf(fptr, "%d  ", accounts[counter - 1].Customer.phone);
    printf("Please Enter the Customer Address : "); // to get user input for customer address.
    scanf(" %[^\n]%*c", person[counter - 1].address);
    strcpy(accounts[counter - 1].Customer.address, person[counter - 1].address);
    fprintf(fptr, "%s  ", accounts[counter - 1].Customer.address);
    fprintf(fptr, "%d ", id);
    printf("Please Enter the Customer Name : "); // to get user input for customer name.
    scanf(" %[^\n]%*c", person[counter - 1].name);
    strcpy(accounts[counter - 1].Customer.name, person[counter - 1].name);
    fprintf(fptr, "%s\n", accounts[counter - 1].Customer.name);
    fclose(fptr); // to close customers.txt file.
    counter++;
}

float calculateLoan(float amount, float period) // to define calculateLoan function.
{
    /*
     *This function is a recursive function.It calculates loan
     *  with using amount and period parameters.
     *
     *Returns loan of the customer.
     */
    if (period == 1)
    {
        return amount * base;
    }
    else
    {
        return base * calculateLoan(amount, period - 1); // recursive call.
    }
}

void newLoan(union Loan loan) // to define newloan function.
{
    /*
     *This function gets user inputs for the customer ID,loan amount,
     *  loan period and interest rate and then it sends this inputs to
     *  calculateLoan function as a parameter and it stores the loan in struct
     *  and loans.txt file.
     *
     *Returns nothing because type of void.
     */
    int id;
    float amount, period;
    int choices;
    FILE *file = fopen("loans.txt", "a+"); // to create loans.txt file and opening for writing.

    printf("Please Enter the ID of Customer : "); // to get user input for customer ID.
    scanf("%d", &id);
    fprintf(file, "%d ", id);
    printf("Please Enter the Amount of Loan : "); // to get user input for amount of loan.
    scanf("%f", &loan.arr[0]);
    amount = loan.arr[0];
    printf("Please Enter the Period of Loan : "); // to get user input for period of loan.
    scanf("%f", &loan.arr[1]);
    period = loan.arr[1];
    loanperiod[id][0] = period;
    fprintf(file, "%.1f ", period);
    printf("Please Enter the Interest Rate : "); // to get user input for interest rate of loan.
    scanf("%f", &loan.arr[2]);
    base = loan.arr[2] + 1;
    if (loanarr[id][0] != 0)
    {
        if (loanarr[id][1] != 0)
        {
            loanarr[id][2] = calculateLoan(amount, period);
        }
        else
            loanarr[id][1] = calculateLoan(amount, period);
    }
    else
        loanarr[id][0] = calculateLoan(amount, period);
    fprintf(file, "%.3f \n", calculateLoan(amount, period)); // to store the loan value in loans.txt file.
}

void getReport() // to define getReport function.
{
    /*
     *This function reads customers.txt file and gets customer ID,phone,
     *   name,address and loan then it prints all in the part of customer
     *   details. In loan details part it gets loan details from file and
     *   it prints total loan and installment of loan of specific customer.
     *
     *Returns nothing because type of void.
     */
    int choice3;
    char s, name[50][20], surname[50][20], address1[50][20], address2[50][20]; // to define some arrays for store datas which are comes from .txt file.
    int id[50], phone[50];                                                     // to define some arrays for store datas which are comes from .txt file.
    int i = 0, k = 0, id1, id2, period1, j;
    float sumloan = 0, totalloan = 0;
    FILE *fptr = fopen("customers.txt", "r"); // to open customers.txt file for reading.

    printf("\nPlease Select\n");
    printf("    1.Customer Details\n"); // for the selection menu.
    printf("    2.Loan Details\n");
    printf("Choice : ");
    scanf("%d", &choice3); // to get user input for selection from menu.
    printf("\n");
    switch (choice3)
    {
    case 1:
        while (!feof(fptr))
        {
            fscanf(fptr, "%d %s %s %d %s %s", &phone[i], address1[i], address2[i], &id[i], name[i], surname[i]); // to read file for customer details.
            i++;
            s = getc(fptr);
            if (s == '\n') // to calculate how many customers in .txt file.
                k++;
        }

        for (i = 0; i < k; i++) // to create a for loop for print customer details.
        {

            printf("Customer ID = %d\n", id[i]);                            // to print customer ID.
            printf("Customer Name = %s %s\n", name[i], surname[i]);         // to print customer name.
            printf("Customer Phone = %d\n", phone[i]);                      // to print customer phone.
            printf("Customer Address = %s %s\n", address1[i], address2[i]); // to print customer address.
            id1 = id[i];
            printf("Loans = [ %.2f ", loanarr[id1][0]); // to print customer loan.
            if (loanarr[id1][1] != 0)
            {
                printf("+ %.2f ", loanarr[id1][1]); // to determine customer has hoe many loan.
                if (loanarr[id1][2] != 0)
                    printf("+ %.2f ", loanarr[id1][2]);
            }
            sumloan = loanarr[id1][0] + loanarr[id1][1] + loanarr[id1][2]; // to calculate total loan of customer.
            printf("] => %.2f\n", sumloan);

            printf("\n");
        }

        break;
    case 2:
        printf("Please Enter the Customer ID :"); // to get user input for the customer ID.
        scanf("%d", &id2);
        totalloan = loanarr[id2][0] + loanarr[id2][1] + loanarr[id2][2];
        period1 = loanperiod[id2][0];
        printf("\nTotal Credit Value = %.2f\n", totalloan); // to print total loan of customer.
        for (j = 1; j <= period1; j++)
            printf("%d. Month Installment = %.2f\n", j, (totalloan / period1)); // to print installments of loan of customer.

        break;

    default:
        break;
    }
}

int main() // to define main function.
{
    int choice;
    struct BankAccount *accounts; // to define struct and unions.
    union Person person[50];
    union Loan loan;

    do
    {
        printf("=====================================\n");
        printf("Welcome to the Bank Management System\n");
        printf("=====================================\n"); // to print the bank management system menu.
        printf("    1. List All Customers\n");
        printf("    2. Add New Customer\n");
        printf("    3. New Loan Application\n");
        printf("    4. Report Menu\n");
        printf("    5. Exit System\n");

        scanf("%d", &choice); // to get user input for selection from menu.
        switch (choice)
        {
        case 1:
            listCustomers(counter, person); // to call listCustomers function for list all customers in system.
            break;
        case 2:
            accounts = (struct BankAccount *)calloc(50, sizeof(struct BankAccount)); // to allocate memory for struct array.
            addCustomer(accounts, person);                                           // to call addCustomer function for add a new customer to system.
            break;
        case 3:
            newLoan(loan); // to call newLoan function for new loan application.
            break;
        case 4:
            getReport(); // to call getReport function for printing customer and loan details.
            break;

        default:
            break;
        }

    } while (choice != 5); // for flow of program.

    return 0; // end of the code..
}