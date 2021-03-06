//CGovernment.h
#ifndef INC_CGOVERNMENT
#define INC_CGOVERNMENT
#include <stdio.h>
#include <vector>
#include "CTax.h"
using namespace std;

class CGovernment :public CAgent
{
	int Tax_revenue;       //税収の合計
	int ave_inc;
	int situgyou_hosyou;	//たぶん使っていない
	int Tax_sum;			//統計用税収合計
	int kyuyo_yosan;		//公務員給与予算
	int hosyou_yosan;		//失業保障金予算
	int hozyokin_yosan;		//企業補助金予算
	int toushi_yosan;		//政府投資予算
	int yugu_yosan;			//優遇政策予算
	int koubai_yosan;		//政府市場購買予算
	vector <int > assignment_producer;		//指定企業番号集合
	CTax *ct;

public:
	CGovernment(){};
	void Collect_tax(int x){Tax_revenue+=x;Tax_sum+=x;};    //税金の回収
	void Show_Tax_revenue();//{printf("Tax_revenue=%d\n",Tax_revenue);};
	void Set_IC();
	void Set_employ(int no){mem_employ.push_back(no);};
	void Set_employ_const_wage(int no){mem_employ_const_wage.push_back(no);};
	void Set_ave_inc(int ave_inc1){ave_inc=ave_inc1;};

	int Get_employ_const_wage(int no){return mem_employ_const_wage[no];};
	int Get_no_employ(){return mem_employ.size();};
	int Get_employer(int no){return mem_employ[no];};
	int Get_ave_inc(){return ave_inc;};
	template<class T,class U> int Decide_buy_retailer_product_no(T &tag,U &mem_product);
	template<class T,class U> int Decide_buy_retailer_product_no_assignment(T &tag,U &mem_product);
	CTax * Get_CTax_class(){return ct;};


	//政府予算セッター
	void Set_hosyou_yosan(int hos){hosyou_yosan=hos;};
	void Set_hozyokin_yosan(int hoz){hozyokin_yosan=hoz;};
	void Set_toushi_yosan(int tos){toushi_yosan=tos;};
	void Set_yugu_yosan(int yu){yugu_yosan=yu;};
	void Set_koubai_yosan(int ko){koubai_yosan=ko;};
	void Set_kyuyo_yosan(int ko){kyuyo_yosan=ko;};

	
	//政府予算ゲッター
	int Get_hosyou_yosan(){return hosyou_yosan;};
	int Get_hozyokin_yosan(){return hozyokin_yosan;};
	int Get_toushi_yosan(){return toushi_yosan;};
	int Get_yugu_yosan(){return yugu_yosan;};
	int Get_tax_sum(){return Tax_sum;};
	int Get_koubai_yosan(){return koubai_yosan;};
	int Get_kyuyo_yosan(){return kyuyo_yosan;};
	void reset_tax_sum(){Tax_sum=0;};


	void Set_shiwake_zeisyu(int i_period,int amount);
	void Set_shiwake_kyuyo(int i_period,int amount);
	void Set_shiwake_koubai(int i_period,int amount);
	void Set_shiwake_invest(int i_period,int amount);
	void Set_shiwake_syouhisya_kouhukin(int i_period,int amount);
	void Set_shiwake_kigyou_kouhukin(int i_period,int amount);
	void Set_shiwake_situgyouhosyou(int i_period,int amount);
	int Get_kigyou_hozyokin_out(){return cac.Get_kigyou_hozyokin_out();};
	void Create_tax_class();
	void Set_taxdate(int i_period,int tax_type,int amount){ct->Set_tax(i_period,tax_type,amount,Agent_no);};

	void Set_assignment_producer(vector<int > member){assignment_producer=member;}
	vector<int > Get_assignment_producer(){return assignment_producer;};



};
template<class T,class U> int CGovernment::Decide_buy_retailer_product_no_assignment(T &tag, U &mem_product)
{
	int i,j,price,checker=0,tag_no=-1,no,checker_2=0;
	for(i=0;i<int(tag.size());i++)		
	{
		if(tag[i]->Get_presence_of_stock()==1)
		{
			for(j=0;j<int(assignment_producer.size());j++)
			{
				if(assignment_producer[j]==tag[i]->Get_Producer_no())
				{
					if(checker==0) 	
					{
						price=tag[i]->Get_price();
						tag_no=i;
						checker=1;
					}
					if(price>tag[i]->Get_price())	
					{
						price=tag[i]->Get_price();
						tag_no=i;
					}
				}
			}
		}
	}

	if(tag_no>-1)
	{
		for(i=0;i<int(mem_product.size());i++)
		{
			if(mem_product[i]->Get_Producer_no()==tag[tag_no]->Get_Producer_no() && mem_product[i]->Get_class_no()==tag[tag_no]->Get_class_no())
			{
				no=i;
				checker_2=1;
				break;
			}
		}
	}

	if(checker_2==0)	no=-1;

	return no;
}
template<class T,class U> int CGovernment::Decide_buy_retailer_product_no(T &tag, U &mem_product)
{
	int i,price,checker=0,tag_no=-1,no,checker_2=0;
	for(i=0;i<int(tag.size());i++)		
	{
		if(tag[i]->Get_presence_of_stock()==1)
		{
			if(checker==0) 	
			{
				price=tag[i]->Get_price();
				tag_no=i;
				checker=1;
			}
			if(price>tag[i]->Get_price())	
			{
				price=tag[i]->Get_price();
				tag_no=i;
			}
		}
	}

	if(tag_no>-1)
	{
		for(i=0;i<int(mem_product.size());i++)
		{
			if(mem_product[i]->Get_Producer_no()==tag[tag_no]->Get_Producer_no() && mem_product[i]->Get_class_no()==tag[tag_no]->Get_class_no())
			{
				no=i;
				checker_2=1;
				break;
			}
		}
	}

	if(checker_2==0)	no=-1;

	return no;
}

void CGovernment::Create_tax_class()
{
	ct=new CTax;
	ct->Set_parameter_class(cpara);
	ct->Set_IC(cpara->GET_PARA_profit_under_line(),10000,cpara->GET_PARA_income_tax_rate(),cpara->GET_PARA_corp_tax_rate());
	
}

void CGovernment::Show_Tax_revenue()
{
	ct->Show_tax(cpara->FI_Get_show_tax());
}

void CGovernment::Set_IC()
{
	Tax_revenue=0;
	Tax_sum=0;

}


void CGovernment::Set_shiwake_zeisyu(int i_period,int amount)
{
	cac.Set_shiwake(i_period,amount,"現金","税金収入","税金収入",amount,0,3);
}

void CGovernment::Set_shiwake_kyuyo(int i_period,int amount)
{
	cac.Set_shiwake(i_period,amount,"未払費用","給与支払","現金",amount,2,0);
}

void CGovernment::Set_shiwake_koubai(int i_period,int amount)
{
	cac.Set_shiwake(i_period,amount,"消耗品","製品購入","現金",amount,1,0);
}
void CGovernment::Set_shiwake_kigyou_kouhukin(int i_period,int amount)
{
	cac.Set_shiwake(i_period,amount,"企業補助金","補助金交付","現金",amount,1,0);
}
void CGovernment::Set_shiwake_invest(int i_period,int amount)
{
	cac.Set_shiwake(i_period,amount,"政府投資","政府投資","現金",amount,1,0);
}
void CGovernment::Set_shiwake_syouhisya_kouhukin(int i_period,int amount)
{
	cac.Set_shiwake(i_period,amount,"消費者交付金","優遇交付金","現金",amount,1,0);
}
void CGovernment::Set_shiwake_situgyouhosyou(int i_period,int amount)
{
	cac.Set_shiwake(i_period,amount,"未払費用","補助金支払","現金",amount,2,0);
}






#endif