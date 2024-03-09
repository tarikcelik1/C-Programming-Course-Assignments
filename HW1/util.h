#ifndef _UTIL_H_
#define _UTIL_H_

int find_divisible(int x, int y, int z);

int find_nth_divisible (n,f_I,z);

int withdrawable_amount(float cash_amount);

int validate_identity_number(char identity_number [11]);

int create_customer(char identity_number[11],int password);

int check_login(char identity_number[11],int password);



#endif /* _UTIL_H_ */