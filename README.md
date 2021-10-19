Write a banking program that simulates the operation of your local bank. You should declare the 
following collection of classes. 
Class Account 
• Data fields: customer (type Customer), balance, account_number, transactions array (type 
transaction*) 
• Member functions: get_balance(), get_customer(), to_string(), set_customer(), 
set_balance() 
Class Savings_Account extends Account 
• Member functions: deposit(), withdraw(), add_interest() 
Class Checking_Account extends Account 
• Member functions: deposit(), withdraw(), add_interest() 
Class Customer 
• Data fields: name, address, age, telephone_number, customer_number 
• Member functions: Accessors and modifiers for data fields 
Classes Senior, Adult, Student, all of which extend class Customer 
• Each has constant data fields, SAVINGS_INTEREST, CHECK_INTEREST, CHECK_CHARGE, and 
OVERDRAFT_PENALTY, that define these values for customers of that type. 
Class Bank 
• Data field: array accounts (type Account*) 
• Member functions: add_account(), make_deposit(), make_withdrawal(), get_account() 
Class Transaction 
• Data fields: customer_number, transaction_type, amount, fees (a string describing unusual 
fees) 
• Member functions: process_tran() 
You need to write all these classes and an application class that interacts with the user. In the 
application, you should first open several accounts and then enter several transactions. A sample 
console output is attached. Note: in addition to the specifications above, you may also need to add 
other data fields and member functions to the classes. You are also allowed to define and 
implement other classes if needed. 