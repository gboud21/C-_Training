#include "IBClient.h"

#include "StdAfx.h"

#include "EClientSocket.h"
#include "EPosixClientSocketPlatform.h"

#include "Contract.h"
#include "Order.h"
#include "OrderState.h"
#include "Execution.h"
#include "CommissionReport.h"
#include "ContractSamples.h"
#include "OrderSamples.h"
#include "ScannerSubscription.h"
#include "ScannerSubscriptionSamples.h"
#include "executioncondition.h"
#include "PriceCondition.h"
#include "MarginCondition.h"
#include "PercentChangeCondition.h"
#include "TimeCondition.h"
#include "VolumeCondition.h"
#include "AvailableAlgoParams.h"
#include "FAMethodSamples.h"
#include "CommonDefs.h"
#include "AccountSummaryTags.h"
#include "Utils.h"

#include <stdio.h>
#include <chrono>
#include <iostream>
#include <thread>
#include <ctime>
#include <fstream>
#include <cstdint>

const int PING_DEADLINE = 2; // seconds
const int SLEEP_BETWEEN_PINGS = 30; // seconds

IBClient::IBClient() :
    m_osSignal(2000)//2-seconds timeout,
    m_pClient(new EClientSocket(this, &m_osSignal)),
	m_state(ST_CONNECT),
	m_sleepDeadline(0),
	m_orderId(0),
    m_pReader(0),
    m_extraAuth(false)
{

}

IBClient::~IBClient()
{
    if (m_pReader)
    {
        delete m_pReader;
        m_pReader = nullptr;
    }

    delete m_pClient;
    m_pClient = nullptr;
}