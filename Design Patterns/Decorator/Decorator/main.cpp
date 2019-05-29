#include "Basic.h"
#include "Advanced.h"
#include "Premium.h"
#include <memory>

using SPAntiVirus = std::shared_ptr<AntiVirus>;

int main(int argc,char** argv)
{
	SPAntiVirus spBasic{ new Basic() };
	spBasic->ProtectionLevel();
	std::cout << std::endl;

	SPAntiVirus spAdvanced{ new AdvancedAntiVirus(*spBasic) };
	spAdvanced->ProtectionLevel();
	std::cout << std::endl;

	SPAntiVirus spPremium{ new PremiumAntiVirus(*spAdvanced) };
	spPremium->ProtectionLevel();
	std::cout << std::endl;

	getchar();
	return 0;
}