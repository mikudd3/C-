#include"TitleInfo.h"
TitleInfo::TitleInfo(string bn, string Title, string au, string pu,
	string dA, int qty, double wh, double re) {
	isbn = bn;
	bookTitle = Title;
	author = au;
	publisher = pu;
	dataAdded = dA;
	qtyOnHand = qty;
	wholesale = wh;
	retail = re;
}
void TitleInfo::seTitle(string Title)
{
	bookTitle = Title;
}
void TitleInfo::seTIsbn(string bn)
{
	isbn = bn;
}
void TitleInfo::setAuthor(string au)
{
	author = au;
}
void TitleInfo::setPub(string pu)
{
	publisher = pu;
}
void TitleInfo::setDataAdded(string dA)
{
	dataAdded = dA;
}
void TitleInfo::setQty(int qty)
{
	qtyOnHand = qty;
}
void TitleInfo::setWholesale(double wh)
{
	wholesale = wh;
}
void TitleInfo::setRetail(double re)
{
	retail = re;
}