//CFunciton.h
//�����ł̑I���A��v�̊m�F���̏��s���֐��̏W�܂�
#ifndef INC_CFUNCTION
#define INC_CFUNCTION
#include <stdio.h>
#include <vector>
#include "CRandum.h"
using namespace std;

class CFunction
{
	
	CRandum *cr;

public:
	CFunction(CRandum *x);

// �����I���n�`�@�x�N�^�[���̐����������_���ɑI��
	//�����x�N�^�����n�`�����I���n���g�p����O�ɕK��������ɗ��Ƃ��Ĕԍ��x�N�^������Ă�����ēx���͂��邱��
	template<class T> vector<int> Cr_random_INTvector_INT(const T& member);	//INT�^�̃x�N�^�����A������INT�̃x�N�^���K�v
	template<class T> vector<int> Cr_random_INTvector_AGE(const T& member);	//INT�^�̃x�N�^�����A�����ɃG�[�W�F���g�x�N�^���K�v�A�G�[�W�F���g�i���o�[���琶��
		//�����I���n_
	template<class T,class U> int Random_choice_int( T& member, U& ite);	//�����ꂽ�x�N�^�[�̒����痐���Ŕԍ���I��ł��̒l�����o���Qint�^�p
	template<class T,class U,class V> int Random_choice_int( T& member, U& ite,V& cra);	//�����ꂽ�x�N�^�[�̒����痐���Ŕԍ���I��ł��̒l�����o���Qint�^�p�A�����N���X�������p��


//��r�n�`�x�N�^���ɊY������x�N�^�����邩�ǂ����𔻒f����
	//��r�n_�G�[�W�F���g�x�N�^
	template<class T,class U> int Comp_AGEvec_VAR(const T& agevec, const U& varia);		//������AGEvec�ŉE�����ϐ��̏ꍇ�̔�r�A�x�N�^�[����i���o�[�����o����v���邱�Ƃ�����ꍇ�͂P��Ԃ�
	template<class T,class U> int Comp_AGEvec_VAR_return_no(const T& agevec,const U& varia);//������AGEvec�ŉE�����ϐ��̏ꍇ�̔�r�A�Y���̓Y�����ԍ���Ԃ�
	template<class T,class U> int Comp_AGEvec_AGEvec(const T& vect, const U& vecgt2);		//������AGEvec�ŉE����AGEvec�̏ꍇ�̔�r�A�x�N�^�[����i���o�[�����o����v���邱�Ƃ�����ꍇ�͂P��Ԃ�
	template<class T,class U> int Comp_AGEvec_AGEvec_return_no(const T& vect,const U& vect2);//������AGEvec�ŉE����AGEvec�̏ꍇ�̔�r�A�Y���̓Y�����ԍ���Ԃ�
	template<class T,class U> int Comp_AGEvec_INTvec(const T& vect, const U& vect2);		//������AGEvec�ŉE����AGEvec�̏ꍇ�̔�r�A�x�N�^�[����i���o�[�����o����v���邱�Ƃ�����ꍇ�͂P��Ԃ�
	template<class T,class U> int Comp_AGEvec_INTvec_return_no(const T& vect,const U& vect2);//������AGEvec�ŉE����AGEvec�̏ꍇ�̔�r�A�Y���̓Y�����ԍ���Ԃ�

	//��r�n_�ϐ��x�N�^
	template<class T,class U> int Comp_INTvec_VAR(const T& vect, const U& varia);		//������INTvec�ŉE�����ϐ��̏ꍇ�̔�r�A��v���邱�Ƃ�����ꍇ�͂P��Ԃ�
	template<class T,class U> int Comp_INTvec_VAR_return_no(const T& vect,const U& varia);//������INTvec�ŉE�����ϐ��̏ꍇ�̔�r�A�Y���̓Y�����ԍ���Ԃ�
	template<class T,class U> int Comp_INTvec_INTvec(const T& vect, const U& varia);		//������INTvec�ŉE����INTvec�̏ꍇ�̔�r�A��v���邱�Ƃ�����ꍇ�͂P��Ԃ�
	template<class T,class U> int Comp_INTvec_INTvec_return_no(const T& vect,const U& varia);//������INTvec�ŉE����INTvec�̏ꍇ�̔�r�A�Y���̓Y�����ԍ���Ԃ�

//�\�[�g�n
	template<class T,class U> vector<int> Sort_NUMvec(const T &vec, U &member,int code);	//�����^�x�N�^�[�̃\�[�g
	template<class T,class U,class V,class W> vector<int> Sort_NUMvec(const T &vec, const U &vec2, V &member, W &no_member,int code);	//�����^�x�N�^�[�̃\�[�g
};

CFunction::CFunction(CRandum *x)
{
	cr=x;	//�����̈����n��
}


template<class T,class U,class V,class W> vector<int> CFunction::Sort_NUMvec(const T &vec, const U &vec2, V &member, W &no_member, int code)
{
	//�����œ��������x�N�^�[�̃\�[�g���s���A�߂�l��2�ڂ̃x�N�^�[�̃\�[�g����
	//3�ځA4�ڂ̓\�[�g�����鎞�̃_�~�[�x�N�^�A�Ăяo���Ƃ��Ɉ�ځA��ڂƂ��ꂼ�ꓯ���ϐ��^�̃x�N�^�����邱��
	//�i����ɂ����INT�ADOUBLE�Ȃǂ̌^�ɂ�炸�{�֐��̗��p���\�ƂȂ�j
	//��ڂ̓����x�N�^�[����Ƀ\�[�g�A��ڂ̓����x�N�^�[�͈�ڂ̃\�[�g�ɍ��킹�ă\�[�g
	//���^�Ȃǂ̏��ʂ�m��ꍇ�ɁA��ڂɋ��^�̏W���A��ڂɂ��̋��^�̃G�[�W�F���g�i���o�[�W��������ƁA���^�̏��ɃG�[�W�F���g�i���o�[���\�[�g����ăA�E�g�v�b�g�����
	//�R�[�h�ɂ���ď����A�~�����قȂ�
	//code:		0=�����Ƀ\�[�g
	//			1=�~���Ƀ\�[�g

	int i, j, temp,temp2;
	
	for(i=0;i<int(vec.size());i++)
	{
		member.push_back(vec[i]);
		no_member.push_back(vec2[i]);
	}

	switch(code)
	{

	case 0:			//����
//		printf("shou\n");
 
		for (i = 0; i < int(member.size()) - 1; i++) 
		{
		
		    for (j = member.size()-1; j > i; j--) 
			{
		         if (member[j-1] > member[j])
				 {		//	x[j - 1] > x[j]) {  /* �O�̗v�f�̕����傫�������� */
		    //	    printf("%d , %d\n",statistics_income[j-1],statistics_income[j]);
					temp=member[j-1];							//	temp = x[j];        /* �������� */
					member[j-1]=member[j];		//	x[j] = x[j - 1];
	                member[j]=temp;							//	x[j - 1]= temp;	

					temp2=no_member[j-1];
					no_member[j-1]=no_member[j];
					no_member[j]=temp2;
				}
	        }
	    }
		break;

	case 1:			//�~��
//		printf("kou\n");
		for (i = 0; i < int(member.size()) - 1; i++) 
		{
		
		    for (j = member.size()-1; j > i; j--) 
			{
		         if (member[j-1] < member[j])
				 {		//	x[j - 1] > x[j]) {  /* �O�̗v�f�̕����傫�������� */
		    //	    printf("%d , %d\n",statistics_income[j-1],statistics_income[j]);
					temp=member[j];							//	temp = x[j];        /* �������� */
					member[j]=member[j-1];		//	x[j] = x[j - 1];
	                member[j-1]=temp;							//	x[j - 1]= temp;	

					temp2=no_member[j];
					no_member[j]=no_member[j-1];
					no_member[j-1]=temp2;
				}
	        }
	    }
		break;
	}

	return no_member;
}

template<class T,class U> vector<int> CFunction::Sort_NUMvec(const T &vec, U &member, int code)
{
	//�����œ��������x�N�^�[�̃\�[�g���s���A
	//2�ڂ̓\�[�g�����鎞�̃_�~�[�x�N�^�A�Ăяo���Ƃ��Ɉ�ځA��ڂƂ��ꂼ�ꓯ���ϐ��^�̃x�N�^�����邱��
	//�i����ɂ����INT�ADOUBLE�Ȃǂ̌^�ɂ�炸�{�֐��̗��p���\�ƂȂ�j
	//�R�[�h�ɂ���ď����A�~�����قȂ�
	//code:		0=�~���Ƀ\�[�g
	//			1=�����Ƀ\�[�g

	int i, j, temp;
	
	for(i=0;i<int(vec.size());i++)
	{
		member.push_back(vec[i]);
	}

	switch(code)
	{

	case 0:			//����
 
		for (i = 0; i < int(member.size()) - 1; i++) 
		{
		
		    for (j = member.size()-1; j > i; j--) 
			{
		         if (member[j-1] > member[j])
				 {		//	x[j - 1] > x[j]) {  /* �O�̗v�f�̕����傫�������� */
		    //	    printf("%d , %d\n",statistics_income[j-1],statistics_income[j]);
					temp=member[j-1];							//	temp = x[j];        /* �������� */
					member[j-1]=member[j];		//	x[j] = x[j - 1];
	                member[j]=temp;							//	x[j - 1]= temp;	
				}
	        }
	    }
		break;

	case 1:			//�~��
		
		for (i = 0; i < int(member.size()) - 1; i++) 
		{
		
		    for (j = member.size()-1; j > i; j--) 
			{
		         if (member[j-1] < member[j])
				 {		//	x[j - 1] > x[j]) {  /* �O�̗v�f�̕����傫�������� */
		    //	    printf("%d , %d\n",statistics_income[j-1],statistics_income[j]);
					temp=member[j];							//	temp = x[j];        /* �������� */
					member[j]=member[j-1];		//	x[j] = x[j - 1];
	                member[j-1]=temp;							//	x[j - 1]= temp;	
				}
	        }
	    }
		break;

		
	}

	return member;
}


template<class T,class U> int CFunction::Comp_AGEvec_VAR(const T &agevec, const U &varia)
{
	int i;
	int checker=0;

	for(i=0;i<int(agevec.size());i++)
	{
		if(agevec[i]->Get_Agent_no()==varia)	
		{
			checker=1;
			break;
		}
	}
	return checker;
}
template<class T,class U> int CFunction::Comp_AGEvec_VAR_return_no(const T &agevec, const U &varia)
{
	int i;
	int no;
	bool checker=false;

	for(i=0;i<int(agevec.size());i++)
	{
		if(agevec[i]->Get_Agent_no()==varia)	
		{
			no=i;
			checker=true;
			break;
		}
	}

	if(checker==false) 	{printf("error CFunction::Comp_agentvec_var_return_no\n"); scanf_s("%d",&no);}

	return no;
}
template<class T,class U> int CFunction::Comp_AGEvec_AGEvec(const T &vect, const U &vect2)
{
	int i,j;
	int checker=0;
	for(i=0;vect.size();i++)
	{
		for(j=0;vect2.size();j++)
		{
			if(vect[i]->Get_Agent_no()==vect2[i]->Get_Agent_no)	checker=1;
		}
	}
	return checker;
}

template <class T,class U> int CFunction::Comp_AGEvec_AGEvec_return_no(const T &vect, const U &vect2)
{
	int i;
	int no;
	bool checker=false;
	for(i=0;vect.size();i++)
	{
		for(i=0;i<int(vect2.size());j++)
		{
			if(vect[i]->Get_Agent_no()==vect2[i]->Get_Agent_no)	
			{
				no=i;
				checker=true;
			}
		}
	}
	
	if(checker==false) 	{printf("error CFunction::Comp_agentvec_var_return_no\n"); scanf("%d",&no);}
	return no;
}

template<class T,class U> int CFunction::Comp_AGEvec_INTvec(const T &vect, const U &vect2)
{
	int i,j;
	int checker=0;
	for(i=0;vect.size();i++)
	{
		for(j=0;vect2.size();j++)
		{
			if(vect[i]->Get_Agent_no()==vect2[i])	checker=1;
		}
	}
	return checker;
}

template<class T,class U> int CFunction::Comp_AGEvec_INTvec_return_no(const T &vect, const U &vect2)
{
	int i;
	int no;
	bool checker=false;
	for(i=0;vect.size();i++)
	{
		for(j=0;vect2.size();j++)
		{
			if(vect[i]->Get_Agent_no()==vect2)	
			{
				no=i;
				checker=true;
			}
		}
	}
	
	if(checker==false) 	{printf("error CFunction::Comp_agentvec_var_return_no\n"); scanf_s("%d",&no);}
	return no;
}



template<class T,class U> int CFunction::Comp_INTvec_VAR(const T &vect, const U &varia)
{
	int i;
	int checker=0;

	for(i=0;i<vect.size();i++)
	{
		if(vect[i]==varia)	checker=1;
	}
	return checker;
}
template<class T,class U> int CFunction::Comp_INTvec_VAR_return_no(const T &vect, const U &varia)
{
	int i;
	int no;
	bool checker=false;

	for(i=0;i<int(vect.size());i++)
	{
		if(vect[i]==varia)	
		{
			no=i;
			checker=true;
		}
	}

	if(checker==false) {printf("error CFunction::Comp_agentvec_var_return_no\n"); scanf_s("%d",&no);}
	return no;
}





template<class T,class U> int CFunction::Random_choice_int( T& member, U& ite)
{
//	vector <int >::iterator dl_re;
	int ni,re_no,j;
	ni=cr->strand(0,member.size()-1);
	re_no=member[ni];
//	dl_re=member.begin();
	ite=member.begin();
	for(j=0;j<int(member.size());j++)
	{
		if(j==ni)
		{
			ite=member.erase(ite);//dl_re);
			break;
		}
		ite++;//dl_re++;
	}
	return re_no;
}

template<class T,class U,class V> int CFunction::Random_choice_int( T& member, U& ite,V& cra)
{
//	vector <int >::iterator dl_re;
	int ni,re_no,j;
	ni=cra->strand(0,member.size()-1);
	re_no=member[ni];
//	dl_re=member.begin();
	ite=member.begin();
	for(j=0;j<int(member.size());j++)
	{
		if(j==ni)
		{
			ite=member.erase(ite);//dl_re);
			break;
		}
		ite++;//dl_re++;
	}
	return re_no;
}

template<class T> vector<int> CFunction::Cr_random_INTvector_INT(const T &member)
{
	int i;
	vector <int> random_vector;
	for(i=0;i<int(member.size());i++)
	{
		random_vector.push_back(member[i]);
	}
	return random_vector;

}
template<class T> vector<int> CFunction::Cr_random_INTvector_AGE(const T &member)
{
	int i;
	vector <int> random_vector;
	for(i=0;i<int(member.size());i++)
	{
		random_vector.push_back(member[i]->Get_Agent_no());
	}
	return random_vector;

}

#endif