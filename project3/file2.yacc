%{
	#include <stdio.h>
	#include <vector>
	#include <string>
	#include <queue>
	#include<iostream>
	int yylex(void);
	extern int yylineno;
	void yyerror(char *);
	using namespace std;
	int deb=0;
	
	struct node
	{
		string content;
		vector<node *> children;
	};

	#define YYSTYPE node*
	node *root = NULL, *temp;

	queue<node*> BFS_queue;

	void print_next_level()
	{
		if(BFS_queue.empty())
			return;

		struct node* temp_node;
		struct node* parent_node;
		queue<node*> temp_queue;

		temp_queue = BFS_queue;

		while(!temp_queue.empty())
		{
			temp_node = temp_queue.front();
			parent_node = BFS_queue.front();
			temp_queue.pop();
			BFS_queue.pop();

			if((temp_node->children).size() > 0)
			{
				cout<<"{"<<parent_node->content<<"} ";
			}

			for(int i=0; i < (temp_node->children).size(); i++)
			{
				cout<<(temp_node->children[i])->content<<" ";
				BFS_queue.push(temp_node->children[i]);			
			}

			//cout<<" ";
		}

		cout<<endl<<endl<<endl;
		print_next_level();

 	}

 	void print_parse_tree(struct node* root)
 	{
 		if(root == NULL)
 			return;

 		cout<<endl<<"Printing Parse Tree..."<<endl<<endl;

 		cout<<root->content<<endl<<endl;

 		for(int i=0; i < (root->children).size(); i++)
		{
			cout<<(root->children[i])->content<<" ";
		}

		cout<<endl;

		for(int i=0; i < (root->children).size(); i++)
		{
			BFS_queue.push(root->children[i]);
		}

		cout<<endl;
		print_next_level();
 	}

%}
%token VAR
%token PROTOTYPE
%token DEF
%token INT
%token BOOL
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

Start: S 
{ 	
	printf("valid\n"); 
	$$=new node; 
	root=$$; 
	$$->content="Start"; 
	$$->children.push_back($1);
} 
;

S: S1 S 
{
	$$=new node; 
	$$->content="S";
	$$->children.push_back($1); 
	$$->children.push_back($2);
} 
| 
{
	$$=new node; 
	$$->content="S"; 
	temp = new node;
	temp->content = "Epsilon";
	$$->children.push_back(temp);
}
;

S1: VAR DV ';' 
{
	$$=new node; 
	$$->content="S1";
	$1 = new node;
	$1->content = "VAR";
	$$->children.push_back($1); 
	$$->children.push_back($2);
	$3 =new node;
	$3->content="Semicolon";
	$$->children.push_back($3);
} 
| VAR DV error
{
	cout<<"missing semicolon at line "<<yylineno<<endl;
	$$=new node; 
	$$->content="S1";
	$1 = new node;
	$1->content = "VAR";
	$$->children.push_back($1); 
	$$->children.push_back($2);
	$3 =new node;
	$3->content="Semicolon";
	$$->children.push_back($3);	
}
| error DV ';'
{
	cout<<"missing var at line "<<yylineno<<endl;
	$$=new node; 
	$$->content="S1";
	$1 = new node;
	$1->content = "VAR";
	$$->children.push_back($1); 
	$$->children.push_back($2);
	$3 =new node;
	$3->content="Semicolon";
	$$->children.push_back($3);	
}
| PROTOTYPE PF ';' 
{
	$$=new node; 
	$$->content="S1"; 
	$1 = new node;
	$1->content = "PROTOTYPE";
	$$->children.push_back($1); 
	$$->children.push_back($2);
	$3 =new node;
	$3->content="Semicolon";
	$$->children.push_back($3);
} 
| PROTOTYPE PF error
{
	cout<<"missing semicolon at line "<<yylineno<<endl;
	$$=new node; 
	$$->content="S1"; 
	$1 = new node;
	$1->content = "PROTOTYPE";
	$$->children.push_back($1); 
	$$->children.push_back($2);
	$3 =new node;
	$3->content="Semicolon";
	$$->children.push_back($3);
}
| error PF ';'
{
	cout<<"missing prototype at line "<<yylineno<<endl;
	$$=new node; 
	$$->content="S1"; 
	$1 = new node;
	$1->content = "PROTOTYPE";
	$$->children.push_back($1); 
	$$->children.push_back($2);
	$3 =new node;
	$3->content="Semicolon";
	$$->children.push_back($3);
}
| DEF INT DF 
{
	$$=new node; 
	$$->content="S1";
	$1 = new node;
	$1->content = "DEF";
	$2=new node;
	$2->content="INT";
	$$->children.push_back($1); 
	$$->children.push_back($2);
	$$->children.push_back($3);
}
| error INT DF
{
	cout<<"missing 'def' at line "<<yylineno<<endl;
	$$=new node; 
	$$->content="S1";
	$1 = new node;
	$1->content = "DEF";
	$2=new node;
	$2->content="INT";
	$$->children.push_back($1); 
	$$->children.push_back($2);
	$$->children.push_back($3);
} 
|
| DEF BOOL DF 
{
	$$=new node; 
	$$->content="S1";
	$1 = new node;
	$1->content = "DEF";
	$2=new node;
	$2->content="BOOL";
	$$->children.push_back($1); 
	$$->children.push_back($2);
	$$->children.push_back($3);
}
| error BOOL DF
{
	cout<<"missing 'def' at line "<<yylineno<<endl;
	$$=new node; 
	$$->content="S1";
	$1 = new node;
	$1->content = "DEF";
	$2=new node;
	$2->content="BOOL";
	$$->children.push_back($1); 
	$$->children.push_back($2);
	$$->children.push_back($3);
} 
;

DV: INT id 
{
	$$=new node; 
	$$->content="DV";
	$1=new node;
	$1->content="INT";
	$$->children.push_back($1); 
	$$->children.push_back($2);
} 
| BOOL id 
{
	$$=new node; 
	$$->content="DV"; 
	$1=new node;
	$1->content="BOOL";
	$$->children.push_back($1); 
	$$->children.push_back($2);
}
;
PF: INT FF 
{
	$$=new node; 
	$$->content="PF"; 
	$1=new node;
	$1->content="INT";
	$$->children.push_back($1); 
	$$->children.push_back($2);

} 

| BOOL FF
{
$$=new node; 
$$->content="PF"; 
$1=new node;
$1->content="BOOL";
$$->children.push_back($1); 
$$->children.push_back($2);
} 

;
FF: id '(' PARAM ')'
{
	$$=new node; 
	$$->content="FF"; 
	$$->children.push_back($1);
	$2 = new node;
	$2->content="(";
	$$->children.push_back($2);
	$$->children.push_back($3);
	$4 = new node;
	$4->content=")";
	$$->children.push_back($4);
} 
| id '(' PARAM error
{
	cout<<"missing ) at line "<<yylineno<<endl;
	$$=new node; 
	$$->content="FF"; 
	$$->children.push_back($1);
	$2 = new node;
	$2->content="(";
	$$->children.push_back($2);
	$$->children.push_back($3);
	$4 = new node;
	$4->content=")";
	$$->children.push_back($4);	
}
| id error PARAM ')'
{
	cout<<"missing ( at line "<<yylineno<<endl;
	$$=new node; 
	$$->content="FF"; 
	$$->children.push_back($1);
	$2 = new node;
	$2->content="(";
	$$->children.push_back($2);
	$$->children.push_back($3);
	$4 = new node;
	$4->content=")";
	$$->children.push_back($4);
}
;
PARAM: INT id PP
{
	$$=new node; 
	$1= new node;
	$1->content = "INT";
	$$->content = "PARAM";
	$$->children.push_back($1);
	$$->children.push_back($2);
	$$->children.push_back($3);
}
| BOOL id PP
{
	$$=new node; 
	$1= new node;
	$1->content = "BOOL";
	$$->content = "PARAM";
	$$->children.push_back($1);
	$$->children.push_back($2);
	$$->children.push_back($3);
}

;
PP: ',' PARAM  
{
	$$=new node; 
	$1= new node;
	$1->content = "Comma";
	$$->content = "PP";
	$$->children.push_back($1);
	$$->children.push_back($2);
}
|
{
	$$=new node; 
	temp= new node;
	temp->content = "Epsilon";
	$$->content = "PP";
	$$->children.push_back(temp);

}
;

DF: id '(' PARAM ')' BEG stmt_list RET V ';' END
{
	$$=new node; 
	$$->content = "DF";
	$$->children.push_back($1);

	$2= new node;
	$2->content = "(";
	$$->children.push_back($2);

	$$->children.push_back($3);

	$4= new node;
	$4->content = ")";
	$$->children.push_back($4);

	$5= new node;
	$5->content = "BEG";
	$$->children.push_back($5);
	
	$$->children.push_back($6);

	$7= new node;	
	$7->content = "RET";
	$$->children.push_back($7);

	$$->children.push_back($8);

	$9= new node;	
	$9->content = ";";
	$$->children.push_back($9);

	$10= new node;	
	$10->content = "END";
	$$->children.push_back($10);

}
| id '(' PARAM ')' BEG stmt_list RET V error END
{
	cout<<"missing semicolon at line "<<yylineno<<endl;
	$$=new node; 
	$$->content = "DF";
	$$->children.push_back($1);

	$2= new node;
	$2->content = "(";
	$$->children.push_back($2);

	$$->children.push_back($3);

	$4= new node;
	$4->content = ")";
	$$->children.push_back($4);

	$5= new node;
	$5->content = "BEG";
	$$->children.push_back($5);
	
	$$->children.push_back($6);

	$7= new node;	
	$7->content = "RET";
	$$->children.push_back($7);

	$$->children.push_back($8);

	$9= new node;	
	$9->content = ";";
	$$->children.push_back($9);

	$10= new node;	
	$10->content = "END";
	$$->children.push_back($10);
}
| id '(' PARAM ')' error stmt_list RET V ';' END
{
	cout<<"missing begin at line "<<yylineno<<endl;
	$$=new node; 
	$$->content = "DF";
	$$->children.push_back($1);

	$2= new node;
	$2->content = "(";
	$$->children.push_back($2);

	$$->children.push_back($3);

	$4= new node;
	$4->content = ")";
	$$->children.push_back($4);

	$5= new node;
	$5->content = "BEG";
	$$->children.push_back($5);
	
	$$->children.push_back($6);

	$7= new node;	
	$7->content = "RET";
	$$->children.push_back($7);

	$$->children.push_back($8);

	$9= new node;	
	$9->content = ";";
	$$->children.push_back($9);

	$10= new node;	
	$10->content = "END";
	$$->children.push_back($10);
}
| id '(' PARAM ')' BEG stmt_list RET V ';' error
{
	cout<<"missing end at line "<<yylineno<<endl;
	$$=new node; 
	$$->content = "DF";
	$$->children.push_back($1);

	$2= new node;
	$2->content = "(";
	$$->children.push_back($2);

	$$->children.push_back($3);

	$4= new node;
	$4->content = ")";
	$$->children.push_back($4);

	$5= new node;
	$5->content = "BEG";
	$$->children.push_back($5);
	
	$$->children.push_back($6);

	$7= new node;	
	$7->content = "RET";
	$$->children.push_back($7);

	$$->children.push_back($8);

	$9= new node;	
	$9->content = ";";
	$$->children.push_back($9);

	$10= new node;	
	$10->content = "END";
	$$->children.push_back($10);
}
;

stmt_list: stmt stmt_list 
{
	$$=new node; 
	$$->content="Stmt list";
	$$->children.push_back($1);
	$$->children.push_back($2);

}
|
{
	$$=new node; 
	temp= new node;
	temp->content = "Epsilon";
	$$->content = "Stmt List";
	$$->children.push_back(temp);
}

;
stmt: ASSIGN id '=' E_or_C ';' 

{
	$$=new node; 
	$$->content="Stmt";
	$1= new node;
	$1->content= "ASSIGN";
	$$->children.push_back($1);
	$$->children.push_back($2);
	$3= new node;
	$3->content= "Equals";
	$$->children.push_back($3);
	$$->children.push_back($4);
	$5= new node;
	$5->content= "Semicolon";
	$$->children.push_back($5);
}
| error id '=' E_or_C ';'
{
	cout<<"missing assign at line "<<yylineno<<endl;
	$$=new node; 
	$$->content="Stmt";
	$1= new node;
	$1->content= "ASSIGN";
	$$->children.push_back($1);
	$$->children.push_back($2);
	$3= new node;
	$3->content= "Equals";
	$$->children.push_back($3);
	$$->children.push_back($4);
	$5= new node;
	$5->content= "Semicolon";
	$$->children.push_back($5);	
}
| ASSIGN id '=' E_or_C error
{
	cout<<"missing semicolon at line "<<yylineno<<endl;
	$$=new node; 
	$$->content="Stmt";
	$1= new node;
	$1->content= "ASSIGN";
	$$->children.push_back($1);
	$$->children.push_back($2);
	$3= new node;
	$3->content= "Equals";
	$$->children.push_back($3);
	$$->children.push_back($4);
	$5= new node;
	$5->content= "Semicolon";
	$$->children.push_back($5);
}

| SCAN id ';' 
{
	$$=new node; 
	$$->content="Stmt";
	$1= new node;
	$1->content= "SCAN";
	$$->children.push_back($1);
	$$->children.push_back($2);
	$3= new node;
	$3->content= "Semicolon";
	$$->children.push_back($3);


}
| SCAN id error 
{
	cout<<"missing semicolon at line "<<yylineno<<endl;
	$$=new node; 
	$$->content="Stmt";
	$1= new node;
	$1->content= "SCAN";
	$$->children.push_back($1);
	$$->children.push_back($2);
	$3= new node;
	$3->content= "Semicolon";
	$$->children.push_back($3);	
}

| PRINT V1 ';' 
{
	$$=new node; 
	$$->content="Stmt";
	$1= new node;
	$1->content= "PRINT";
	$$->children.push_back($1);
	$$->children.push_back($2);
	$3= new node;
	$3->content= "Semicolon";
	$$->children.push_back($3);

}
| PRINT V1 error
{
	cout<<"missing semicolon at line "<<yylineno<<endl;
	$$=new node; 
	$$->content="Stmt";
	$1= new node;
	$1->content= "PRINT";
	$$->children.push_back($1);
	$$->children.push_back($2);
	$3= new node;
	$3->content= "Semicolon";
	$$->children.push_back($3);	
}
| WHILE expr BEG stmt_list END 
{
	$$=new node; 
	$$->content="Stmt";
	$1= new node;
	$1->content= "WHILE";
	$$->children.push_back($1);
	$$->children.push_back($2);
	$3= new node;
	$3->content= "BEG";
	$$->children.push_back($3);
	$$->children.push_back($4);
	$5= new node;
	$5->content= "END";
	$$->children.push_back($5);
}
| IF expr BEG stmt_list END
{
	$$=new node; 
	$$->content="Stmt";
	$1= new node;
	$1->content= "IF";
	$$->children.push_back($1);
	$$->children.push_back($2);
	$3= new node;
	$3->content= "BEG";
	$$->children.push_back($3);
	$$->children.push_back($4);
	$5= new node;
	$5->content= "END";
	$$->children.push_back($5);
}
;
E_or_C: expr 
{

	$$=new node;
	$$->content="E_or_C";
	$$->children.push_back($1);
}
| CALL id '(' PARAM1 ')'
{
	$$=new node; 
		$$->content="E_or_C";
	$1= new node;
		$1->content= "CALL";
		$$->children.push_back($1);
	$$->children.push_back($2);
	$3= new node;
		$3->content= "(";
		$$->children.push_back($3);
	$$->children.push_back($4);
	$5= new node;
		$5->content= ")";
		$$->children.push_back($5);

}
| CALL id error PARAM1 ')'
{
	cout<<"missing ( at line "<<yylineno<<endl;
	$$=new node; 
		$$->content="E_or_C";
	$1= new node;
		$1->content= "CALL";
		$$->children.push_back($1);
	$$->children.push_back($2);
	$3= new node;
		$3->content= "(";
		$$->children.push_back($3);
	$$->children.push_back($4);
	$5= new node;
		$5->content= ")";
		$$->children.push_back($5);}
| CALL id '(' PARAM1 error
{
	cout<<"missing ) at line "<<yylineno<<endl;
	$$=new node; 
		$$->content="E_or_C";
	$1= new node;
		$1->content= "CALL";
		$$->children.push_back($1);
	$$->children.push_back($2);
	$3= new node;
		$3->content= "(";
		$$->children.push_back($3);
	$$->children.push_back($4);
	$5= new node;
		$5->content= ")";
		$$->children.push_back($5);
}
;
PARAM1: V PP1
{
	$$= new node;
	$$->content= "PARAM1";
	$$->children.push_back($1);
	$$->children.push_back($2);
}
| 
{
	$$=new node;
	$$->content="PARAM1"; 
	temp = new node;
	temp->content = "Epsilon";
	$$->children.push_back(temp);
}
; 
PP1: ',' PARAM1 
{
	$$ = new node;
	$$->content = "PP1";

	$1 = new node;
	$1->content = ",";

	$$->children.push_back($1);
	$$->children.push_back($2);
}
|
{
	$$ = new node;
	$$->content = "PP1";

	temp = new node;
	temp->content = "Epsilon";

	$$->children.push_back(temp);
}
;

V: num 
{
	$$ = new node;
	$$->content = "V";

	$$->children.push_back($1);
}
|
 id
 {
 	$$ = new node;
	$$->content = "V";

	$$->children.push_back($1);
 }
;
V1: id 
{
	$$ = new node;
	$$->content = "V1";

	$$->children.push_back($1);
}
| num 
{
	$$ = new node;
	$$->content = "V1";

	$$->children.push_back($1);
}
| SPACE 
{
	$$ = new node;
	$$->content = "V1";

	$1 = new node;
	$1->content = "SPACE";

	$$->children.push_back($1);
}
| ENDL
{
	$$ = new node;
	$$->content = "V1";

	$1 = new node;
	$1->content = "ENDL";

	$$->children.push_back($1);
}
;
num: NUM 
{
	$$ = new node;
	$$->content = "V1";

	$1 = new node;
	$1->content = "NUM";

	$$->children.push_back($1);
}
| '~' NUM
{
	$$ = new node;
	$$->content = "V";

	$1 = new node;
	$1->content = "~";
	$2 = new node;
	$2->content = "NUM";

	$$->children.push_back($1);
	$$->children.push_back($2);
}
;
id: ID 
{
	$$=new node;
	$$->content="id";
	$1=new node;
	$1->content="ID";
	$$->children.push_back($1);
}

| '~' ID
{
	$$=new node;
	$$->content="id";
	$1=new node;
	$1->content="~";
	$2=new node;
	$2->content="ID";
	$$->children.push_back($1);	
	$$->children.push_back($2);	
}	
;

expr: O E1
{
	$$=new node;
	$$->content="expr";
	$$->children.push_back($1);	
	$$->children.push_back($2);	
}
;
E1: '|' O E1 
{
	$$=new node;
	$$->content="E1";
	$1=new node;
	$1->content="|";
	$$->children.push_back($1);	
	$$->children.push_back($2);
	$$->children.push_back($3);
}
|
{
	$$=new node;
	$$->content="E1";
	temp=new node;
	temp->content="Epsilon";
	$$->children.push_back(temp);
}
;

O: A O1
{
	$$=new node;
	$$->content="O";
	$$->children.push_back($1);	
	$$->children.push_back($2);
}
;
O1: '&' A O1
{
	$$=new node;
	$$->content="O1";
	$1=new node;
	$1->content="&";
	$$->children.push_back($1);	
	$$->children.push_back($2);
	$$->children.push_back($3);
} 
|
{
	$$=new node;
	$$->content="O1";
	temp=new node;
	temp->content="Epsilon";
	$$->children.push_back(temp);
}
;

A: M A1
{
	$$=new node;
	$$->content="A";
	$$->children.push_back($1);	
	$$->children.push_back($2);	
}
;
A1: '%' M A1 
{
	$$=new node;
	$$->content="A1";
	$1=new node;
	$1->content="%";
	$$->children.push_back($1);	
	$$->children.push_back($2);
	$$->children.push_back($3);
}
|
{
	$$=new node;
	$$->content="A1";
	temp=new node;
	temp->content="Epsilon";
	$$->children.push_back(temp);
}
;

M: G M1
{
	$$=new node;
	$$->content="M";
	$$->children.push_back($1);	
	$$->children.push_back($2);
}
;
M1: '>' G M1
{
	$$=new node;
	$$->content="M1";
	$1=new node;
	$1->content=">";
	$$->children.push_back($1);	
	$$->children.push_back($2);
	$$->children.push_back($3);

}
|
{
	$$=new node;
	$$->content="M1";
	temp=new node;
	temp->content="Epsilon";
	$$->children.push_back(temp);
}
;

G: L G1
{
	$$=new node;
	$$->content="G";
	$$->children.push_back($1);	
	$$->children.push_back($2);
}
;
G1: '<' L G1 
{
	$$=new node;
	$$->content="G1";
	$1=new node;
	$1->content="<";
	$$->children.push_back($1);	
	$$->children.push_back($2);
	$$->children.push_back($3);
}
|
{
	$$=new node;
	$$->content="G1";
	temp=new node;
	temp->content="Epsilon";
	$$->children.push_back(temp);
}
;

L: AS L1
{
	$$=new node;
	$$->content="L";
	$$->children.push_back($1);	
	$$->children.push_back($2);
}
;
L1: '+' AS L1 
{
	$$=new node;
	$$->content="L1";
	$1=new node;
	$1->content="+";
	$$->children.push_back($1);	
	$$->children.push_back($2);
	$$->children.push_back($3);
}
| '-' AS L1 
{
	$$=new node;
	$$->content="L1";
	$1=new node;
	$1->content="-";
	$$->children.push_back($1);	
	$$->children.push_back($2);
	$$->children.push_back($3);
}
|
{
	$$=new node;
	$$->content="L1";
	temp=new node;
	temp->content="Epsilon";
	$$->children.push_back(temp);
}
;

AS: MD AS1
{
	$$=new node;
	$$->content="AS";
	$$->children.push_back($1);	
	$$->children.push_back($2);
}
;
AS1: '*' MD AS1 
{
	$$=new node;
	$$->content="AS1";
	$1=new node;
	$1->content="*";
	$$->children.push_back($1);	
	$$->children.push_back($2);
	$$->children.push_back($3);
}
| '/' MD AS1 
{
	$$=new node;
	$$->content="AS1";
	$1=new node;
	$1->content="/";
	$$->children.push_back($1);	
	$$->children.push_back($2);
	$$->children.push_back($3);
}
|
{
	$$=new node;
	$$->content="AS1";
	temp=new node;
	temp->content="Epsilon";
	$$->children.push_back(temp);
}
;

MD: num 
{
	$$ = new node;
	$$->content = "MD";
	$$->children.push_back($1);
}
| id 
{
	$$ = new node;
	$$->content = "MD";
	$$->children.push_back($1);	
}
| '(' expr ')'
{
	$$ = new node;
	$$->content = "MD";

	$1 = new node;
	$1->content = "(";
	$3 = new node;
	$3->content = ")";

	$$->children.push_back($1);
	$$->children.push_back($2);
	$$->children.push_back($3);
}
| '(' expr error
{
	cout<<"missing ) at line "<<yylineno<<endl;
	$$ = new node;
	$$->content = "MD";

	$1 = new node;
	$1->content = "(";
	$3 = new node;
	$3->content = ")";

	$$->children.push_back($1);
	$$->children.push_back($2);
	$$->children.push_back($3);	
}
| error expr ')'
{
	cout<<"missing ( at line "<<yylineno<<endl;
	$$ = new node;
	$$->content = "MD";

	$1 = new node;
	$1->content = "(";
	$3 = new node;
	$3->content = ")";

	$$->children.push_back($1);
	$$->children.push_back($2);
	$$->children.push_back($3);
}
; 


%%
void yyerror(char *s) {

	extern int yylineno;
	fprintf(stderr, "At line %d %s\n", yylineno , s);
 
 fprintf(stderr, "%s\n", s);

}

int main(void) {
 yyparse();
 cout<<"DONE"<<endl; 

 print_parse_tree(root);
 return 0;
}