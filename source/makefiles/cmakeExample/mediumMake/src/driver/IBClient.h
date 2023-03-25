#ifndef IB_CLIENT_H
#define IB_CLIENT_H

#include "EWrapper.h"
#include "EWrapper_prototypes.h" // events
#include "EReaderOSSignal.h"
#include "EReader.h"

#include <memory>
#include <vector>

class EClientSocket;

class IBClient : public EWrapper
{
public:
    IBClient();
    ~IBClient();

	void setConnectOptions(const std::string&);
	void processMessages();

	bool connect(const char * host, int port, int clientId = 0);
	void disconnect() const;
	bool isConnected() const;

private:
    void pnlOperation();
    void pnlSingleOperation();
	void tickDataOperation();
	void tickOptionComputationOperation();
	void delayedTickDataOperation();
	void marketDepthOperations();
	void realTimeBars();
	void marketDataType();
	void historicalDataRequests();
	void optionsOperations();
	void accountOperations();
	void orderOperations();
	void ocaSamples();
	void conditionSamples();
	void bracketSample();
	void hedgeSample();
	void contractOperations();
	void marketScanners();
	void fundamentals();
	void bulletins();
	void testAlgoSamples();
	void financialAdvisorOrderSamples();
	void financialAdvisorOperations();
	void testDisplayGroups();
	void miscelaneous();
	void reqFamilyCodes();
	void reqMatchingSymbols();
	void reqMktDepthExchanges();
	void reqNewsTicks();
	void reqSmartComponents();
	void reqNewsProviders();
	void reqNewsArticle();
	void reqHistoricalNews();
	void reqHeadTimestamp();
	void reqHistogramData();
	void rerouteCFDOperations();
	void marketRuleOperations();
	void continuousFuturesOperations();
    void reqHistoricalTicks();
    void reqTickByTickData();
	void whatIfSamples();

	void reqCurrentTime();

	void printContractMsg(const Contract& contract);
	void printContractDetailsMsg(const ContractDetails& contractDetails);
	void printContractDetailsSecIdList(const TagValueListSPtr &secIdList);
	void printBondContractDetailsMsg(const ContractDetails& contractDetails);

	//! [socket_declare]
	EReaderOSSignal m_osSignal;
	EClientSocket * const m_pClient;
	//! [socket_declare]
	State m_state;
	time_t m_sleepDeadline;

	OrderId m_orderId;
	EReader *m_pReader;
    bool m_extraAuth;
	std::string m_bboExchange;
};
#endif //IB_CLIENT_H