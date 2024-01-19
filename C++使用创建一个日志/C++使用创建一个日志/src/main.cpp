#include <iostream>

#define LOGMES(type) void type(const char* message){if(m_Loglevel>=LogLevel##type)std::cout << "["#type"]: " << message << std::endl;}

class Log
{
public:
	const int LogLevelError = 0;
	const int LogLevelWarming = 1;
	const int LogLevelInfor = 2;
private:
	int m_Loglevel = LogLevelInfor;

public:
	void SetLevel(const int level)
	{
		m_Loglevel = level;
	}
	LOGMES(Error)
	LOGMES(Warming)
	LOGMES(Infor)
};

int main()
{
	Log log;
	log.SetLevel(log.LogLevelWarming);
	log.Warming("Clannad");
	log.Infor("Clannad");
	log.Error("Clannad");
}