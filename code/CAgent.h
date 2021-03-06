//CAgent.h
#ifndef INC_CAGENT
#define INC_CAGENT
#include "CRandum.h"
#include "CProduct_class.h"
#include "CProduct.h"
#include "CAccount.h"
//#include "CBlance.h"
#include"CParameter.h"
#include"CFunction.h"
//#include "CTax.h"
#include <vector>
using namespace std;
class CAgent
{
protected:

	int Agent_no;
	int Agent_type;
           //Agent_type=10; 一般消費者 Consumer
		   //Agent_type=20; 一般消費者向け生産者 Retailer
	       //Agent_tuype=30;生産者向け生産者（原料を生産する) wholesaler
	int ncase;//ncase=0:総勘定元帳をout3へのプリントアウト
			  //ncase!=0:総勘定元帳をプリントアウトしない
	int nkessan;//nkessan=0：out3へのプリントアウト
				//nkessan!=0:out3へのプリントアウトをしない

//〜〜〜〜int〜〜〜〜〜
	int kisyu_genkin,kimatu_genkin;
	int kisyu_yokin,kimatu_yokin;
	int kisyu_loan_s,kimatu_loan_s;
	int kisyu_loan_l,kimatu_loan_l;
	int kisyu_shihon,kimatu_shihon;
	int kisyu_mibarai,kimatu_mibarai;
	int kisyu_seihin,kimatu_seihin;
	int kisyu_genryouhi,kimatu_genryouhi;
	int kisyu_setubi,kimatu_setubi;
//〜〜〜long long〜〜〜〜
	long long kisyu_genkin_l;
	long long kisyu_shihon_l;
//〜〜〜〜〜〜〜〜〜〜〜
	int bonus;//ボーナス給
	int bank_no;//預金を預ける銀行番号
	int bankruptcy_p;//倒産準備カウント
	int buy_p;
	int sum_q;

	int tax;      //税金(仮)


	
	vector <int> mem_employ;				//雇用しているエージェント番号
	vector <int> mem_employ_const_wage;
	vector <int> mem_loan_s;
	vector <int> mem_loan_l;
	vector <int> mem_s_risoku;
	vector <int> mem_hensai;
	vector <int> mem_material;
	vector <int> mem_retail_buy;

	int n_class;//市場にある製品種別の最大数
	int ncr_p;//各生産者が生産する製品種別の数
	int ncr_c;//各消費者が購入する製品種別の数
	int total_constant_wage;//従業員の固定給与の総額
	int total_price_genka;//製造原価
	int sum_price_genka;//実製造原価
	int price_genka;//製品１個あたりの製造原価
	int rieki;//利益
	double depo_rate;//各エージェントの貯蓄率
	int reseave;//準備金
	int i_period;
	int i_period_first;//借り始め期
	int touki_zyunrieki;
	int sum_const_wage;//給与合計

	CAccount cac;
	CTax ct;
	CFunction *cf;
	
	vector <int > mem_ncr_p;//生産する製品種別番号の集合
	vector <int > mem_ncr_c;//購入する製品種別番号の集合
	CRandum *cr;
	CProduct *pr;
	CParameter *cpara;
	CProduct_class *cpc;

	vector <CProduct *> mem_buy;
	vector <CProduct_class *> mem_buy_retailer_product_data;	//リテイラー製品購入判断のためのプロダクトクラス集合
																//現在使用者：リテイラー、ホールセラー



public:


	

	CProduct* Get_product(CProduct *pr){return pr;};
	CAgent();//コンストラクタ


	void Calc_sum_const_wage(){sum_const_wage=0; for(int i=0;i<int(mem_employ_const_wage.size());i++) sum_const_wage=mem_employ_const_wage[i];};
	void Create_mem_buy_retailer_product_data();
	

//	~CAgent();//デストラクタ


////////セッター//////////////

	void Set_parameter_class(CParameter * cpar){cpara=cpar; cac.Set_parameter_class(cpar);};
	void Set_i_period(int i_p1){i_period=i_p1;};
	void Set_n_class(int n_class1){n_class=n_class1;};
	void Set_ncr_p(int ncr_p1){ncr_p=ncr_p1;};
	void Set_ncr_c(int ncr_c1){ncr_c=ncr_c1;};
	void Set_Agent_no(int Agent_no1){Agent_no=Agent_no1;cac.Set_Agent_no(Agent_no);};
	void Set_Agent_type(int Agent_type1){Agent_type=Agent_type1;};
	void Set_randum(CRandum *cr1){cr=cr1;};

	void Set_F_show_tax(FILE *fi){printf("teeeeeeeeest\n");ct.Set_F_show_tax(fi);};
	void Set_tax_class(CTax *cta){cac.Set_CTax_class(cta);};








	
	
	

	///////ゲッター///////
	int Get_ncr_p(){return ncr_p;};
	int Get_ncr_c(){return ncr_c;};
	double Get_depo_rate(){return depo_rate;};		//depo_rate自体はCConsumerのset_dapo_rate_new3で利用されている
	int Get_Agent_no(){return Agent_no;};
	int Get_Agent_type(){return Agent_type;};
	int Get_touki_zyunrieki(){return touki_zyunrieki;};
	int Get_sum_const_wage(){return sum_const_wage;};
	


	int Get_uriagetotal(){return cac.Get_uriage_total();};
	int Get_zaiko(){return cac.Get_zaiko();};
	int Get_genryou(){return cac.Get_genka();};
	int Get_rieki_zyouyo(){return cac.Get_kimatu_riekizyouyo();};
	int Get_touki_rieki_zyouyo(){return cac.Get_touki_riekizyouyo();};


	void Init(int Agent_no1,int Agent_type1);
	






	/////ファイル書き込み用///////
	void Show_employ();
	void Show_employ_no();




	virtual void Show_bought_product();

	

//	void Before();
	void Kessan(int i,int *rieki1,int i_period);

	//会計処理　現金預金出納帳
																				//code=2:現金減少
	void Reset_genyokin_sutioutyou(){cac.Reset_genyokin_suitoutyou();};
//~~int
	int Get_genkin_suitoutyou_zandaka(){return cac.Get_genkin_suitoutyou_zandaka();};
	int Get_yokin_suitoutyou_zandaka(){return cac.Get_yokin_suitoutyou_zandaka();};
//~~long long 
	__int64 Get_genkin_suitoutyou_zandaka_l(){return cac.Get_genkin_suitoutyou_zandaka_l();};
	__int64 Get_yokin_suitoutyou_zandaka_l(){return cac.Get_yokin_suitoutyou_zandaka_l();};
//~~


	//会計処理　仕分け、決算時
	void Set_shiwake_buy_retailer_product(int i_period,int amount);
	void Set_kisyu_shihon(int shihon1){kisyu_shihon=shihon1;};
//〜〜〜〜〜longlong型〜〜〜〜〜〜〜
	void Set_kisyu_shihon_l(long long shihon1){kisyu_shihon_l=shihon1;};
//〜〜〜〜〜〜〜〜〜〜〜〜〜〜〜〜〜


	void Set_kimatu_shihon(int shihon1){kimatu_shihon=shihon1;};
	void Set_shiwake_uke_risoku(int i_period,int interest);

	
	void Set_loan_s(int no){mem_loan_s.push_back(no);};
	void Set_loan_l(int no){mem_loan_l.push_back(no);};
	void Set_s_risoku(int no){mem_s_risoku.push_back(no);};
	void Set_hensai(int no){mem_hensai.push_back(no);};
	void Set_material(int no){mem_material.push_back(no);};
	void Set_re_buy(int no){mem_retail_buy.push_back(no);};

	int Get_loan_s_zandaka();
	int Get_loan_l_zandaka();
	int Get_s_risoku_zandaka();
	int Get_hensai();
	int Get_material(){return mem_material[0];};
	void Erase_material(){mem_material.erase(mem_material.begin());};
	int Get_retail_buy(int no){return mem_retail_buy[no];};
	void Erase_retail_buy();

	
	void Set_buy_p(int x){buy_p=x;};
	void Plus_buy_p(int x){buy_p+=x;};
	void Reset_buy_p(){buy_p=0;};
	int Get_buy_p(){return buy_p;};
	void Set_sum_q(int x){sum_q=x;};
	int Get_sum_q(){return sum_q;};
	
	void Set_bankr_p(int bankr_p1){bankruptcy_p=bankr_p1;};
	int Get_bankr_p(){return bankruptcy_p;};
	void Set_i_period_first(int ri){i_period_first=ri;printf("i_period=%d\n",i_period_first);};	//おそらく借入ができなかったの最初の期
	int Get_i_period_first(){return i_period_first;};

	void Set_rieki_ac(int ri){rieki=ri;};
	int Get_rieki_ac(){return rieki;};
	void CAgent::Kessan2(int i,int *rieki1,int i_period);

	void Set_price_genka(int genka){price_genka=genka;};
	int Get_price_genka(){return price_genka;};
	void Set_total_price_genka(int genka){total_price_genka=genka;};
	int Get_total_price_genka(){return total_price_genka;};
	void Set_sum_price_genka(int sum_genka){sum_price_genka=sum_genka;};
	int Get_sum_price_genka(){return sum_price_genka;};
	void Set_total_constant_wage(int total){total_constant_wage=total;};
	int Get_constant_wage(){return total_constant_wage;};
	void Set_bonus(int b){bonus=b;};
	int Get_bonus(){return bonus;};
	void Set_bank_no(int i1){bank_no=i1;};
	int Get_bank_no(){return bank_no;};
	void Set_ncase(int ncase1){ncase=ncase1;};//総勘定元帳のout3へのプリントアウト用
	void Set_nkessan(int nkessan1){nkessan=nkessan1;};//決算結果のout3へのプリントアウト用

///0期以降用：CAccountからのデータ取出//////////
	
	int Get_genkin_ac(){int gen=cac.Get_kamoku(0,"現金");return gen;};
	long long Get_genkin_ac_l(){long long gen=cac.Get_kamoku_l(0,"現金");return gen;};
	int Get_yokin_ac(){int yo=cac.Get_kamoku(0,"預金");return yo;};
	int Get_loan_s_ac(){int lo=cac.Get_kamoku(2,"短期借入金");return lo;};
	int Get_loan_l_ac(){int lol=cac.Get_kamoku(2,"長期借入金");return lol;};
	int Get_shihon_ac(){int shi=cac.Get_kamoku(2,"株主資本");return shi;};
	int Get_setubi_ac(){int setubi=cac.Get_kamoku(0,"設備");return setubi;};
	int Get_genryo_ac(){int genryo=cac.Get_kamoku(0,"原料");return genryo;};
	int Get_loan_s_b_ac(){int lob=cac.Get_kamoku(0,"短期貸出金");return lob;};
	int Get_loan_l_b_ac(){int lolb=cac.Get_kamoku(0,"長期貸出金");return lolb;};
	int Get_yokin_b_ac(){int yob=cac.Get_kamoku(2,"預金_Bank");return yob;};


	int Get_genryou_out(){return cac.Get_genryou_out();};
	int Get_setubi_out(){return cac.Get_setubi_out();};
	int Get_ukerisi_out(){return cac.Get_ukerisi_out();};
	int Get_siharisi_out(){return cac.Get_siharisi_out();};
	int Get_uriage_out(){return cac.Get_uriage_out();};
	int Get_kyuyo_out(){return cac.Get_kyuyo_out();};
	int Get_bonus_out(){return cac.Get_bonus_out();};
	int Get_rieki_out(){return cac.Get_rieki_out();};
	int Get_genkasyoukyaku_out(){return cac.Get_genkasyoukyaku_out();};
	int Get_zaiko_out(){return cac.Get_zaiko_out();};
	int Get_kyuyo_c_out(){return cac.Get_kyuyo_c_out();};
	int Get_houzinzei_out(){return cac.Get_houzinzei_out();};
	int Get_buy_retailer_product_out(){return cac.Get_buy_retailer_out();};
	int Get_touki_mibarai_bonus(){return cac.Get_touki_mibarai_bonus();};

	int Get_kimatu_riekizyouyo(){return cac.Get_kimatu_riekizyouyo();};
	int Get_syoumouhin_out(){return cac.Get_syoumouhin_out();};
//〜〜〜〜〜int〜〜〜〜〜
	void Set_kisyu_zandaka();
//〜〜〜long long〜〜〜〜
	void Set_kisyu_zandaka_l();
//〜〜〜〜〜〜〜〜〜〜〜〜
	int Get_karikashi(int index,char *kamoku){return cac.Get_karikashi_ac(index,kamoku);};
	int Get_kisyu_ac(int index,char *kamoku){return cac.Get_kisyu_ac(index,kamoku);};

////////////////////////////////////////////////
	void Show_kimatu_zandaka(int Agent_type,FILE *out3);
	void Show_kisyu_zandaka(int Agent_type,FILE *out3);
	/////////税金///////////
	void Tax_calc(int rieki);//{if(rieki>0) tax=int(rieki*0.1);};
	int Get_tax(){return cac.Get_mibarai_tax();};
	int Get_shouhi_tax(){ return cac.Get_mibarai_shouhi_tax();};
	void Set_shiwake_houzin_tax(int i_period, int tax);
	void Set_shiwake_shouhi_tax(int i_period, int tax); 
	
	void Tax_calc_syotoku(int inco);
	
	void Set_shiwake_syotoku_tax(int i_period,int tax);
	int Get_touki_zeimae_rieki(){return cac.Get_touki_zeimae_rieki();};
	void Set_class_buy_retailer_data(vector <int> mem_ncr_r);
	int Get_buy_retailer_data_class_no(int no){return mem_buy_retailer_product_data[no]->Get_class_no();};
	int Get_class_buy_retailer_data_size(){return mem_buy_retailer_product_data.size();};

	int Tyotiku_touki_zeigorieki(){return cac.Tyotiku_get_zeigorieki();};
	int Tyotiku_touki_zyunsoneki(){return cac.tyotiku_get_zyunneki();};




};

CAgent::CAgent()
{
	pr=new CProduct;
	

}
void CAgent::Set_class_buy_retailer_data(vector <int> mem_ncr_r)
{
	int i,j;
	int ncount;
	int size;
	int crr;
	int size_ncr;
	size_ncr=mem_ncr_r.size();
	size=mem_buy_retailer_product_data.size();
	for(i=0;i<int(mem_buy_retailer_product_data.size());i++){
		ncount=0;
restart:
		crr=cr->strand(0,size_ncr-1);
		//同じ乱数でないことを確認し同じ乱数なら生成しなおす。
		for(j=0;j<int(mem_buy_retailer_product_data.size());j++)
		{
			if(mem_ncr_r[crr]==mem_buy_retailer_product_data[j]->Get_class_no() && ncount<1000) 
			{
				ncount++;
				goto restart;
			}
		}
		mem_buy_retailer_product_data[i]->Set_class_no(mem_ncr_r[crr]);
	}
}
void CAgent::Create_mem_buy_retailer_product_data()
{
	int i;
	for(i=0;i<ncr_c;i++){
		cpc=new CProduct_class;
		//pc->Set_class_no(cr->strand(1,10));
		cpc->Set_Consumer_no(Get_Agent_no());
		cpc->Set_Consumer_type(Get_Agent_type());
		cpc->Set_ncr_c(ncr_c);
		cpc->Set_q_buy(0);
		cpc->Set_test(cpara->FI_Get_test());
		cpc->Set_IC(cpara->GET_PARA_max_memo_time(),cpara->GET_PARA_max_reac_flag(),0);//0=max_e_flag//consumerなので0
		mem_buy_retailer_product_data.push_back(cpc);
	}

}



void CAgent::Show_kimatu_zandaka(int Agent_type,FILE *out3)
{
	
	int x;
	if(Agent_type==50) x=1;//Bank
	else x=0;
	cac.Show_kimatu_zandaka(x,out3);
}
void CAgent::Show_kisyu_zandaka(int Agent_type,FILE *out3)
{
	int x;
	if(Agent_type==50) x=1;//Bank
	else x=0;
	cac.Show_kisyu_zandaka(x,out3);
}


void CAgent::Show_employ_no()
{
	int size;
	size=mem_employ.size();
	int i;
	int sum=0;
	printf("consumer _no");
	for(i=0;i<size;i++)
	{
		printf(" %3d ",mem_employ[i]);
	}
	printf("\n");
}
void CAgent::Show_employ()
{
	int size;
	size=mem_employ.size();
	int i;
	int sum=0;
	fprintf(cpara->FI_Get_employ_file(),"         consumer_no as employee ");
	for(i=0;i<size;i++)
	{
		fprintf(cpara->FI_Get_employ_file()," %3d ",mem_employ[i]);
	}
	fprintf(cpara->FI_Get_employ_file(),"  constant_wage ");
	for(i=0;i<size;i++)
	{
		fprintf(cpara->FI_Get_employ_file()," %d ",mem_employ_const_wage[i]);
		sum+=mem_employ_const_wage[i];
	}
	total_constant_wage=sum;//従業員の固定給与の総額
	fprintf(cpara->FI_Get_employ_file(),"total_constant_wage=%d ",total_constant_wage);
}



void CAgent::Set_kisyu_zandaka()	//Createのときのみ使用される
{
	cac.Set_kisyu_re();//すべての期首残高を0とする（reset）
	cac.Set_kimatu_re();//すべての期末残高を0とする（reset)
	cac.Set_kisyu_zandaka(kisyu_genkin,kisyu_yokin,kisyu_loan_s,kisyu_loan_l,kisyu_shihon,kisyu_mibarai,kisyu_seihin,kisyu_genryouhi,kisyu_setubi);
}
void CAgent::Set_kisyu_zandaka_l()	//Createのときのみ使用される
{
	cac.Set_kisyu_re();//すべての期首残高を0とする（reset）
	cac.Set_kimatu_re();//すべての期末残高を0とする（reset)
	cac.Set_kisyu_zandaka_l(kisyu_genkin_l,kisyu_yokin,kisyu_loan_s,kisyu_loan_l,kisyu_shihon_l,kisyu_mibarai,kisyu_seihin,kisyu_genryouhi,kisyu_setubi);
}

int CAgent::Get_loan_s_zandaka()
{
	int i;
	int size;
	int sum;
	sum=0;
	size=mem_loan_s.size();
	for(i=0;i<size;i++){
		sum+=mem_loan_s[i];
	}
	return sum;
}
int CAgent::Get_loan_l_zandaka()
{
	int i;
	int size;
	int sum;
	sum=0;
	size=mem_loan_l.size();
	for(i=0;i<size;i++){
		sum+=mem_loan_l[i];
	}
	return sum;
}
int CAgent::Get_s_risoku_zandaka()
{
	int i;
	int size;
	int sum;
	sum=0;
	size=mem_s_risoku.size();
	for(i=0;i<size;i++){
		sum+=mem_s_risoku[i];
	}
	return sum;
}
int CAgent::Get_hensai()
{
	int i;
	int size;
	int sum;
	sum=0;
	size=mem_hensai.size();
	for(i=0;i<size;i++){
		sum+=mem_hensai[i];
	}
	return sum;
}
void CAgent::Erase_retail_buy()
{
	int i;
	int size;
	size=mem_retail_buy.size();
	for(i=0;i<size;i++){
		mem_retail_buy.pop_back();
	}
}
void CAgent::Kessan(int i,int *rieki1,int i_period)
{
	cac.Set_Agent_type(Agent_type);
	cac.Set_nkessan(nkessan);
	cac.Kessan(i_period,ncase,cpara->FI_Get_out3(),cpara->FI_Get_out3_csv());
	Set_rieki_ac(cac.Get_rieki());
}
void CAgent::Kessan2(int i,int *rieki1,int i_period)
{
	cac.Set_Agent_type(Agent_type);
	cac.Set_nkessan(nkessan);
	cac.Kessan(i_period,ncase,cpara->FI_Get_out3(),cpara->FI_Get_out3_csv());
	Set_rieki_ac(cac.Get_rieki());
}
void CAgent::Show_bought_product()
{
	int i;
	int size;
	size=mem_buy.size();
	for(i=0;i<size;i++){
		fprintf(cpara->FI_Get_out(),"  producer no=,%3d, class no=,%3d, price=,%6d, lot_no=,%3d, \n",mem_buy[i]->Get_Producer_no(),mem_buy[i]->Get_class_no(),mem_buy[i]->Get_price(),mem_buy[i]->Get_lot_no());
	}
}

void CAgent::Init(int Agent_no1,int Agent_type1)
{
	Agent_no=Agent_no1;
	Agent_type=Agent_type1;
}

void CAgent::Tax_calc(int rieki)
{
	ct.Calc_houzin_tax(rieki);
	tax=ct.Get_calculated_houzin_tax();
}

void CAgent::Tax_calc_syotoku(int inco)
{
	ct.Calc_syotoku_tax(inco);
	tax=ct.Get_calculated_syotoku_tax();
}
void CAgent::Set_shiwake_buy_retailer_product(int i_period,int amount)
{
		cac.Set_shiwake(i_period,amount,"リテイラー製品","R製品購入","現金",amount,1,0);
		cac.Set_shiwake(i_period,amount,"低額固定資本形成","低額固定資本購買","リテイラー製品",amount,0,1);
		cac.Set_shiwake(i_period,amount,"減価償却費","低額固定減価償却","低額固定資本形成",amount,1,0);
}


void CAgent::Set_shiwake_syotoku_tax(int i_period,int tax)
{
	cac.Set_shiwake(i_period,0,"所得税","税金支払","現金",tax,1,0);
	cac.Set_shiharai_tax(tax);
}
void CAgent::Set_shiwake_houzin_tax(int i_period,int tax)
{
	cac.Set_shiwake(i_period,0,"法人税","税金支払","現金",tax,1,0);
	cac.Set_shiharai_tax(tax);

}
void CAgent::Set_shiwake_shouhi_tax(int i_period, int tax)
{
	cac.Set_shiwake(i_period,0,"消費税","税金支払","現金",tax,1,0);
	cac.Set_shiharai_shouhi_tax(tax);
}

void CAgent::Set_shiwake_uke_risoku(int i_period,int interest)
{
	cac.Set_shiwake(i_period,interest,"預金","預金受取利息","受取利息",interest,0,3);
}

#endif


