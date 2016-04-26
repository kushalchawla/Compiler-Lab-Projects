%{
	#include <stdio.h>
	#include <vector>
	#include <string>
	#include <queue>
	#include <map>
	#include <set>
	#include <iostream>
	#include <fstream>
	#include <algorithm>
	
	


	int yylex(void);
	extern int yylineno;
	void yyerror(char *);
	using namespace std;
	map<int,int> labels;
	struct node
	{
		string name;
		int type; //int 0; char 1, bool 2
		int val;
		int operation; //for expressions
	};

	void yyerror(char *);

	extern char* yytext;

	struct symtab_entry
	{
		string name;
		int type; //int 0; char 1, bool 2
		int val;
		int offset;
	};

	int scope = 0;
	
	vector<symtab_entry> default_push;
	ofstream fout;

	//
		map<string,int> func_ret_type;
		set<string> prototyped_functions;
	//
	string f_name;
	int global_frt;
	int global_fun_no = 0;
	map< int, vector<symtab_entry> > f_symtab;
	vector<symtab_entry> p_symtab;

	//
	#define YYSTYPE node

	int cal_symtab_size()
	{
		int size=0;
		map<int, vector<symtab_entry> >::iterator it;

		for(it=f_symtab.begin(); it != f_symtab.end(); it++)
		{
			size = size + it->second.size();
		}

		return size;
	}

	int search_symtab(string key, int * x)
	{
		int temp_scope = scope;
		while(temp_scope > 0 )
		{
			if(f_symtab.find(temp_scope) != f_symtab.end())
			{
				for(int i=0; i<f_symtab[temp_scope].size(); i++ )
				{
					if(key == f_symtab[temp_scope][i].name)
					{
						*x = f_symtab[temp_scope][i].val;
						return -1 * (f_symtab[temp_scope][i].offset + 4);
					}
				}
			}

			temp_scope--;
		}
		return 1;
	}


	int search_p_symtab(string key, int * x)
	{
		for(int i=0;i<p_symtab.size();i++)
		{
			//cout<<"**"<<p_symtab[i].name<<endl;
			//cout<<"###"<<key<<endl;
			if(p_symtab[i].name == key )
			{
				*x = p_symtab[i].val;	
				return 4*i + 4;
			}
		}

		return -1;
	}
	

	void search_and_store(string name)
	{
		int v;
		int off= search_symtab(name,&v);
		if(off<=0)
		{
			//fout << "li $t0 " << off <<"\n";
			fout<< "sw $t0 "<<off<<"($fp)\n";
			// $$.val=*v;
		}	
		else
		{
			off = search_p_symtab(name,&v);	
			if(off > 0)
			{
				fout<< "sw $t0 "<<off<<"($fp)\n";
				// $$.val=*v;
			}	

			else
			{
				cout << "Variable " << name <<" not declared\n";
			}
		}
	}

	void search_and_load(string name)
	{
		int v;
		int off= search_symtab(name,&v);
		if(off<=0)
		{
			fout<< "lw $t0 "<<off<<"($fp)\n";

			//fout<< "sw $t0 "<<off<<"($fp)\n";
			// $$.val=*v;
		}	
		else
		{
			off = search_p_symtab(name,&v);	
			if(off > 0)
			{
				fout<< "lw $t0 "<<off<<"($fp)\n";
				//fout<< "sw $t0 "<<off<<"($fp)\n";
				// $$.val=*v;
			}	

			else
			{
				cout << "Variable " << name <<" not declared\n";
			}
		}
	}

	symtab_entry get_symtab_entry(string key)
	{
		int temp_scope = scope;
		while(temp_scope > 0 )
		{
			if(f_symtab.find(temp_scope) != f_symtab.end())
			{
				for(int i=0; i<f_symtab[temp_scope].size(); i++ )
				{
					if(key == f_symtab[temp_scope][i].name)
					{
						return f_symtab[temp_scope][i];
					}
				}
			}

			temp_scope--;
		}

		for(int i=0;i<p_symtab.size();i++)
		{
			if(p_symtab[i].name == key )
			{
				return p_symtab[i];
			}
		}

		cout<<"Variable undeclared : "<<key<<endl;
		exit(0);
	}

	int comp_arith_op(int first, int second)
	{
		if( (first + second) == 3)
			return 0;

		return 1;
	}

	int assign_compat(int first, int second)
	{
		if( (first + second) == 3)
			return 0;

		return 1;	
	}


%}
%token VAR
%token PROTOTYPE
%token DEF
%token INT
%token BOOL
%token CHAR
%token BEG
%token END
%token RET
%token ASSIGN
%token CALL
%token SCAN
%token PRINT
%token ENDL
%token SPACE
%token WHILE
%token IF
%token THEN
%token ID
%token NUM
%token CH
%%

Start: S {cout<<"S parsed\n";}
;

S: S1 S 
| 

;

S1: PROTOTYPE PF ';' 
{

}
| DEF DF
;


PF: INT 
{
	global_frt=0;
}
FF
| BOOL 
{
	global_frt=1;
}FF
| CHAR 
{
	global_frt=2;
}FF
;
FF: id '(' PARAM ')'
{
	if(prototyped_functions.find($1.name) != prototyped_functions.end())
	{
		cout<<"Function name "<<$1.name <<"already used\n";
		return 0;
	}

	else
	{
		prototyped_functions.insert($1.name);
		func_ret_type[$1.name]=global_frt;
		cout<<$1.name<<" function prototyped\n";
	}
}
;
PARAM: INT id 
{
	$2.type=0;
	symtab_entry new_one;
	new_one.type=$2.type;
	new_one.name=$2.name;
	new_one.offset = 0;
	p_symtab.push_back(new_one);
}
PP 

| BOOL id 
{
	$2.type=2;
	symtab_entry new_one;
	new_one.type=$2.type;
	new_one.name=$2.name;
	new_one.offset = 0;
	p_symtab.push_back(new_one);
}
PP
| CHAR id 
{
	$2.type=1;
	symtab_entry new_one;
	new_one.type=$2.type;
	new_one.name=$2.name;
	new_one.offset = 0;
	p_symtab.push_back(new_one);
}
PP
|
;
PP: ',' PARAM  

|
;

DF: INT id
{
	global_fun_no++;

	if(global_fun_no == 1 && $2.name != "main")
	{
		cout<<"first function should be main\n";
		return 0;
	}
	cout<<"DF int parsed\n";
	scope++;

	if($2.name != "main" && prototyped_functions.find($2.name) == prototyped_functions.end())
	{
		cout<<"\nfunction '"<< $2.name<<"' not pototyped before use\n";
	}

	else
	{
		f_name=$2.name;
		cout<<$2.name<<" definition begins .. \n";
		fout<<$2.name<<":\n";
		fout<<"move $fp $sp\n";	
		fout<<"sw $ra 0($sp)\n";
		fout<<"addiu $sp $sp -4\n\n";
	}
	p_symtab.clear();
	f_symtab.clear();
} DF1
| BOOL id
{
	cout<<"DF bool parsed\n";
	scope++;
	if($2.name != "main" && prototyped_functions.find($2.name) == prototyped_functions.end())
	{
		cout<<"\nfunction '"<< $2.name<<"' not pototyped before use\n";
	}

	else
	{
		f_name=$2.name;
		cout<<$2.name<<" definition begins .. \n";
		fout<<$2.name<<":\n";
		fout<<"move $fp $sp\n";	
		fout<<"sw $ra 0($sp)\n";
		fout<<"addiu $sp $sp -4\n\n";
	}
	p_symtab.clear();
	f_symtab.clear();
}
DF1
| CHAR id 
{
	cout<<"DF char parsed\n";
	scope++;
	if($2.name != "main" && prototyped_functions.find($2.name) == prototyped_functions.end())
	{
		cout<<"\nfunction '"<< $2.name<<"' not pototyped before use\n";
	}

	else
	{
		f_name=$2.name;
		cout<<$2.name<<" definition begins .. \n";
		fout<<$2.name<<":\n";
		fout<<"move $fp $sp\n";	
		fout<<"sw $ra 0($sp)\n";
		fout<<"addiu $sp $sp -4\n\n";
	}
	p_symtab.clear();
	f_symtab.clear();

		
}DF1

;
DF1: '(' PARAM ')' { reverse(p_symtab.begin(), p_symtab.end()); } BEG stmt_list RET expr ';' END 
{
	fout<<"\naddiu $sp $sp "<<4*f_symtab[scope].size()<<"\n";
	fout<<"lw $ra 4($sp)\n";
	fout<<"addiu $sp $sp "<<4*p_symtab.size() + 8<<"\n";
	fout<<"lw $fp 0($sp)\n";

	if(f_name=="main")
	{
		fout<<"li $v0 10\nsyscall\n\n\n";
	}
	else
	{
		fout<<"jr $ra\n\n\n";
	}
	scope--;
	p_symtab.clear();
	f_symtab.clear();
}


stmt_list: stmt stmt_list 
|
;
stmt: ASSIGN id '=' E_or_C ';' 
{
	symtab_entry new_sym=get_symtab_entry($2.name);
	cout<<"***";
	cout<<new_sym.name<<" "<<new_sym.type<<endl;
	cout<<$4.type<<endl;
	cout<<"***\n";
	if(assign_compat(new_sym.type,$4.type))
	{
		if($2.type==2)
		{
			//assign 1 for +ve to $t0
			/*
			beq $t0,$zero,L1
			li $t0 1
			L1:
			*/	
			if(labels.find(0)==labels.end())
			{
				labels[0]=0;
			}
			labels[0]++;
			fout<<"beq $t0,$zero,"<<"scope0_label"<<labels[0]<<"\n";
			fout<"li $t0 1\n";
			fout<<"scope0_label"<<labels[0]<<":\n";

		}
		search_and_store($2.name);	
	}
	else
	{
		cout<<"Not compatible for assignment operation-- "<<$4.type<<" to "<<new_sym.type<<endl;
		return 0;
	}
	
	

}
| WHILE expr 
{
	if(labels.find(scope)==labels.end())
	{
		labels[scope]=0;
	}
	labels[scope]++;
	int l1=labels[scope];

	labels[scope]++;
	int l2=labels[scope];

	fout<<"scope"<<scope<<"_label"<<l1<<":\n";
	fout<<"beq $t0,$zero,scope"<<scope<<"_label"<<l2<<"\n\n"; 


	scope++;
}
BEG stmt_list END 
{
	fout<<"j scope"<<scope-1<<"_label"<<labels[scope-1]-1<<"\n\n";
	fout<<"scope"<<scope-1<<"_label"<<labels[scope-1]<<":\n";

	fout<<"addiu $sp $sp "<<4*f_symtab[scope].size()<<"\n\n";
	///////
	f_symtab[scope].clear();
	scope--;

}
| IF expr 
{
	//check expr, do scope ++ jmp to label
	//////////
	if(labels.find(scope)==labels.end())
	{
		labels[scope]=0;
	}
	labels[scope]++;
	fout<<"beq $t0,$zero,scope"<<scope<<"_label"<<labels[scope]<<"\n\n"; 
	//////////
	scope++;
}
BEG stmt_list END
{
	//delete variables from stack and in f_symtab do scope--; ...write termination code
	//////

	fout<<"scope"<<scope-1<<"_label"<<labels[scope-1]<<":\n";
	fout<<"addiu $sp $sp "<<4*f_symtab[scope].size()<<"\n\n";
	///////
	f_symtab[scope].clear();
	scope--;
	

}
| VAR DV ';'
;
DV: INT id 
{
	$2.type=0;
	symtab_entry new_one;
	new_one.type=$2.type;
	new_one.name=$2.name;
	new_one.offset = cal_symtab_size()*4;
	f_symtab[scope].push_back(new_one);
	fout<<"li $t0,0\nsw $t0, 0($sp)\naddiu $sp $sp -4\n";
}
| BOOL id 
{
	$2.type=2;
	symtab_entry new_one;
	new_one.type=$2.type;
	new_one.name=$2.name;
	new_one.offset = cal_symtab_size()*4;
	f_symtab[scope].push_back(new_one);
	fout<<"li $t0,0\nsw $t0, 0($sp)\naddiu $sp $sp -4\n";
}
| CHAR id
{
	$2.type=1;
	symtab_entry new_one;
	new_one.type=$2.type;
	new_one.name=$2.name;
	new_one.offset = cal_symtab_size()*4;
	f_symtab[scope].push_back(new_one);
	fout<<"li $t0,0\nsw $t0, 0($sp)\naddiu $sp $sp -4\n";
}
;
E_or_C: expr 
{
	$$.type=$1.type;
}

| CALL id 
{
//whether prototyped error checking 

	$$.type=func_ret_type[$2.name];

	fout << "sw $fp 0($sp)\n";
	fout<<"addiu $sp $sp -4\n";
}'(' PARAM1 ')'
{
	fout<<"jal "<<$2.name<<endl;

}
;
PARAM1: V PP1

| 

; 
PP1: ',' PARAM1 

|

;

V: num 
{
	fout<<"li $t0, "<<$1.val<<endl;
	fout<<"sw $t0, 0($sp)\n";
	fout<<"addiu $sp $sp -4\n";
}
| ch
{
	fout<<"li $t0, "<<$1.val<<endl;
	fout<<"sw $t0, 0($sp)\n";
	fout<<"addiu $sp $sp -4\n";	
}
|
 id
{
	int v;
	int offset = search_symtab($1.name,&v);
	if( offset <= 0)
	{
		cout<<"symbol table : "<<$1.name<<endl;
		fout<<"lw $t0 "<<offset<<"($fp)\n";
		fout<<"sw $t0 0($sp)\n";
		fout<<"addiu $sp $sp -4\n";
	}

	else
	{
		offset = search_p_symtab($1.name,&v);
		if( offset > 0 )
		{
			cout<<"param table : "<<$1.name<<endl;
			fout<<"lw $t0 "<<offset<<"($fp)\n";
			fout<<"sw $t0 0($sp)\n";
			fout<<"addiu $sp $sp -4\n";
		}

		else
		{
			cout<<"variable "<<$1.name<<" not declared\n";
			cout<<p_symtab.size()<<endl;
			cout<<f_symtab.size()<<endl;
			cout<<f_symtab[1].size()<<endl;
		}
	}
	
}
;

num: NUM 
{
	$$.val = atoi(yytext);
}
;

ch: CH
{
	$$.val=(int)yytext[1];
}
;
id: ID 
{
	//cout<<"***"<<yytext<<"***"<<endl;
	$$.name = yytext;
}

;

expr: Term Term1
{
	if( comp_arith_op( $1.type, $2.type) )
	{
		$$.type=min($1.type,$2.type);
		switch($2.operation)
		{
			case 1: fout<<"add $t0 $t0 $t3\n";	
					break;

			case 2: fout<<"sub $t0 $t3 $t0\n";	
					break;

			case 3: fout<<"mul $t0 $t0 $t3\n";	
					break;

			case 4: fout<<"div $t0 $t3 $t0\n";	
					break;

			case 5:	if(labels.find(0)==labels.end())
					{
						labels[0]=0;
					}
					labels[0]++;

					
					fout<<"sub $t4 $t3 $t0\n";
					fout<"li $t0 0\n";
					fout<<"bgez $t4,"<<"scope0_label"<<labels[0]<<"\n";
					fout<"li $t0 1\n";
					fout<<"scope0_label"<<labels[0]<<":\n";
					
					break;

			case 6: if(labels.find(0)==labels.end())
					{
						labels[0]=0;
					}
					labels[0]++;

					
					fout<<"sub $t4 $t0 $t3\n";
					fout<"li $t0 0\n";
					fout<<"bgez $t4,"<<"scope0_label"<<labels[0]<<"\n";
					fout<"li $t0 1\n";
					fout<<"scope0_label"<<labels[0]<<":\n";
					
					break;
		}
	}
	
	else
	{
		cout<<"Not compatible for arithmetic operation-- "<<$1.type<<" and "<<$2.type<<endl;
	}
}
;


Term1: '+' {fout<<"move $t3 $t0\n";} Term
{
	$$.operation = 1;
	$$.type = $2.type;

}

| '-' {fout<<"move $t3 $t0\n";} Term
{
	$$.operation = 2;
	$$.type = $2.type;

}
| '*' {fout<<"move $t3 $t0\n";} Term
{
	$$.operation = 3;
	$$.type = $2.type;

}

| '/' {fout<<"move $t3 $t0\n";} Term
{
	$$.operation = 4;
	$$.type = $2.type;

}

| '<' {fout<<"move $t3 $t0\n";} Term
{
	$$.operation = 5;
	$$.type = $2.type;

}
| '>' {fout<<"move $t3 $t0\n";} Term
{
	$$.operation = 6;
	$$.type = $2.type;

}
| 
{
	$$.type=10;
}
;


Term: id
{
	search_and_load($1.name);
	symtab_entry new_sym=get_symtab_entry($1.name);
	$$.type=new_sym.type;

}
| num
{
	fout << "li $t0  " <<$1.val <<"\n";
	$$.type=0;
}
| ch
{
	fout << "li $t0  " <<$1.val <<"\n";
	$$.type=1;	
}
;

%%
void yyerror(char *s) {

	extern int yylineno;
	fprintf(stderr, "At line %d %s\n", yylineno , s);
 
 fprintf(stderr, "%s\n", s);

}

int main(void) 
{
	fout.open("mips_code.asm");

	fout<<".text\n.globl main\n\n";
	yyparse();
	cout<<"DONE"<<endl; 
	fout.close();
	return 0;
}