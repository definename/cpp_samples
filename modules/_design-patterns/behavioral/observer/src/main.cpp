#include "pch.h"
#include "Timer.h"
#include "AnalogClock.h"
#include "DigitalClock.h"

void _tmain(int argc, TCHAR* argv[])
{
	try
	{
		boost::shared_ptr<Timer> timer(new Timer());
		boost::shared_ptr<AnalogClock> analog(new AnalogClock());
		boost::shared_ptr<DigitalClock> digital(new DigitalClock());

		boost::uuids::uuid aId = timer->Attach(analog);
		boost::uuids::uuid dId = timer->Attach(digital);

		timer->Notify();
		boost::this_thread::sleep(boost::posix_time::seconds(1));
		timer->Notify();

		timer->Dettach(aId);
		timer->Dettach(dId);
	}
	catch (const std::exception& e)
	{
		_tcerr << "Error occurred: " << e.what() << std::endl;
	}
}