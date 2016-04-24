struct node
{
	
	string content;
	vector<node *> children;
	
	int type; // 0-int, 1 -char, 2-bool>
	string name;
	int val;
};