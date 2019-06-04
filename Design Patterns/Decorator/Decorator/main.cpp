#include "stdafx.h"
#include <memory>

using SPAntiVirus = std::shared_ptr<AntiVirus>;

int main(int argc,char** argv)
{
	SPAntiVirus spBasic = std::make_shared<Basic>();
	spBasic->Protect();
	std::cout << std::endl;

	SPAntiVirus spBasic_StopHackers = std::make_shared<StopHackers>(*spBasic);
	spBasic_StopHackers->Protect();
	std::cout << std::endl;

	SPAntiVirus spBasic_StopHackers_Encrypt = std::make_shared<Encrypt>(*spBasic_StopHackers);
	spBasic_StopHackers_Encrypt->Protect();
	std::cout << std::endl;
	std::cout << std::endl;


	SPAntiVirus spBasic_ShopSafe = std::make_shared<ShopSafe>(*spBasic);
	spBasic_ShopSafe->Protect();
	std::cout << std::endl;

	SPAntiVirus spBasic_ShopSafe_StopHackers = std::make_shared<StopHackers>(*spBasic_ShopSafe);
	spBasic_ShopSafe_StopHackers->Protect();
	std::cout << std::endl;

	getchar();		/// for keeping console in open
	return 0;
}