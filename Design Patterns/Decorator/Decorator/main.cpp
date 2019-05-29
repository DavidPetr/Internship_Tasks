#include "Basic.h"
#include "Advanced.h"
#include "Premium.h"
#include <memory>

using SPAntiVirus = std::shared_ptr<AntiVirus>;

int main(int argc,char** argv)
{
	SPAntiVirus pBasic{ new Basic() };
	pBasic->ProtectionLevel();
	std::cout << std::endl;

	SPAntiVirus pAdvanced{ new AdvancedAntiVirus(*pBasic) };
	pAdvanced->ProtectionLevel();
	std::cout << std::endl;

	SPAntiVirus pPremium{ new PremiumAntiVirus(*pAdvanced) };
	pPremium->ProtectionLevel();
	std::cout << std::endl;

	getchar();
	return 0;
}