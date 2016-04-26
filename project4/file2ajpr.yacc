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
	
	struct node
	{
		string name;
		int type; //int 0; char 1, bool 2
		int val;
		bool is_epsilon; 
		int operation; // + 1; - 2; * 3; / 4; 
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
		set<string> prototyped_functions;
	//
	string f_name;
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


PF: INT FF 
| BOOL FF
| CHAR FF
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
DF1: '(' PARAM ')' { reverse(p_symtab.begin(), p_symtab.end()); } BEG stmt_list RET V ';' END 
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
	cout<<"DF int parsed\n";
	p_symtab.clear();
	f_symtab.clear();
}


stmt_list: stmt stmt_list 
|
;
stmt: ASSIGN id '=' E_or_C
{
	//fout << "move $t1 $t0\n";
	search_and_store($2.name);
}';' 
| WHILE expr BEG stmt_list END 
| IF expr BEG stmt_list END
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

| CALL id 
{
//whether prototyped error checking
	fout << "sw $fp 0($sp)\n";
	fout<<"addiu $sp $sp -4\n";
}'(' PARAM1 ')'

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
|
 id
{
	int v;
	int offset = search_symtab($1.name,&v);
	if( offset <= 0)
	{
		cout<<"symbol table : "<<$1.name<<endl;
		fout<<"sw $t0 "<<offset<<"($fp)\n";
	}

	else
	{
		offset = search_p_symtab($1.name,&v);
		if( offset > 0 )
		{
			cout<<"param table : "<<$1.name<<endl;
			fout<<"sw $t0 "<<offset<<"($fp)\n";
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
id: ID 
{
	//cout<<"***"<<yytext<<"***"<<endl;
	$1.name = yytext;
	$$.name = yytext;

	//search_and_load($1.name);
	
	$$.is_epsilon=0;
}
;

expr: O {
	
	//fout <<"sw $t0 0($sp)\naddiu $sp $sp -4\n";
	$$.is_epsilon=0;
}
E1
{
	if($2.is_epsilon==0)
	{
		fout <<"lw $t1 4($sp)\nadd $t0 $t1 $t0\naddiu $sp $sp 4\n";
	}		
	else
		fout << "addiu $sp $sp 4\n";
	
}
;
E1: '|' O {
	$$.is_epsilon=0;
	//fout <<"sw $t0 0($sp)\naddiu $sp $sp -4\n";
}
 E1 
{
	if($2.operation==1)
	{
		if($2.is_epsilon==0)
			fout <<"lw $t1 4($sp)\nadd $t0 $t1 $t0\naddiu $sp $sp 4\n";
		else
			fout <<"addiu $sp $sp 4\n";
	}
	else
	{
		if($2.is_epsilon==0)
			fout <<"lw $t1 4($sp)\nsub $t0 $t1 $t0\naddiu $sp $sp 4\n";
		else
			fout <<"addiu $sp $sp 4\n";
	}	

	
}
|
	{
		$$.is_epsilon=1;
	}
;

O: A O1


;
O1: '&' A O1
 
|

;

A: M A1

;
A1: '%' M A1 

|

;

M: G M1

;
M1: '>' G M1

|

;

G: L G1

;
G1: '<' L G1 

|
;

L: AS {
	fout <<"AS NOT EPSILONsw $t0 0($sp)\naddiu $sp $sp -4\n";
	$$.is_epsilon=0;
} AS1{
	if($2.operation==1)
	{
		if($2.is_epsilon==0)
			fout <<"lw $t1 4($sp)\nadd $t0 $t1 $t0\naddiu $sp $sp 4\n";
		else
			{
				fout <<"addiu $sp $sp 4\n";
			}
	}
	else if($2.operation==2)
	{
		if($2.is_epsilon==0)
			fout <<"lw $t1 4($sp)\nsub $t0 $t1 $t0\naddiu $sp $sp 4\n";
		else
			fout <<"addiu $sp $sp 4\n";
	}	

	
}
;
AS1:'+' L{
	$$.operation=1;
	$$.is_epsilon=0;

}
| '-' L
{
	$$.operation=2;
	$$.is_epsilon=0;
}
|
{
	$$.operation=11;
	$$.is_epsilon=1;
}
;

AS: MD {
	fout <<"MD NOT EPSILONsw $t0 0($sp)\naddiu $sp $sp -4\n";
	$$.is_epsilon=0;
} MD1
{
	if($2.operation==3)
	{
		if($2.is_epsilon==0)
			fout <<"lw $t1 4($sp)\nmul $t0 $t1 $t0\naddiu $sp $sp 4\n";
		else
			fout <<"addiu $sp $sp 4\n";
	}
	else if($2.operation==4)
	{
		if($2.is_epsilon==0)
			fout <<"lw $t1 4($sp)\ndiv $t0 $t1 $t0\naddiu $sp $sp 4\n";
		else
			fout <<"addiu $sp $sp 4\n";
	}	

}
;
MD1: '*' AS
{
    $$.operation=3;
	$$.is_epsilon=0;	
} 
| '/' AS 
{
	$$.operation=4;
	$$.is_epsilon=0;
}
|
{   $$.operation=11;
	$$.is_epsilon=1;
}
;

MD: num 
{
	fout << "li $t0  " <<$1.val <<"\n";
	$$.is_epsilon=0;
}
| id 
{
	search_and_load($1.name);
	$$.is_epsilon=0;
}
| '(' expr ')'
{
	$$.is_epsilon=0;
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