#ifndef ACCOUNT_CONTROLLER_H
#define ACCOUNT_CONTROLLER_H

#include <iostream>

class AccountController
{
public:
    AccountController();
    ~AccountController();

    // --- Returns the Instance of Account Controller
    static AccountController *getInstance();

    // --- Destroys the instance of Account Controller
    static void destroyInstance();

    void test();

private:
    // --- Singleton Instance of AccountController
    static AccountController *mp_instance;

    const std::string m_username;
    const std::string m_password;
    
};
#endif //ACCOUNT_CONTROLLER_H