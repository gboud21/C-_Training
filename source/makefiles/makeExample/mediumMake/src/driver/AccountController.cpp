#include "AccountController.h"

AccountController *AccountController::mp_instance = nullptr;

AccountController * AccountController::getInstance()
{
    if(nullptr == mp_instance)
    {
        mp_instance = new AccountController();
    }

    return mp_instance;
}

void AccountController::destroyInstance()
{
    if(nullptr != mp_instance)
    {
        delete mp_instance;
        mp_instance = nullptr;
    }
}

AccountController::AccountController() :
    m_username("tmpUser"), m_password("temp")
{

}

AccountController::~AccountController()
{
    
}

void AccountController::test()
{
    std::cout << m_username << std::endl;
}