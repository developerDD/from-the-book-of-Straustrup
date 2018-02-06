#include<iostream>
#include<string>
#include<map>

using namespace std;
enum Token_value
{
	NAME, NUMBER, END, PLUS = '+', MINUS = '-', MUL = '*', DIV = '/', PRINT = ';', ASSIGN = '=', LP = '(', RP = ')'
};
Token_value curr_tok = PRINT;
//addition/subtraction
double term(bool);
double prim(bool);
Token_value get_token();
double error(const string&);
double expr(bool get)
{
	double left = term(get);
	for (;;)
	{
		switch (curr_tok)
		{
		case PLUS:
			left += term(true);
			break;
		case MINUS:
			left -= term(true);
			break;
		default:
			return left;
		}
	}
}

//division/multiplication

double term(bool get)
{
	double left = prim(get);
	for (;;)
	{
		switch (curr_tok)
		{
		case MUL:
			left *= prim(true);
			break;
		case DIV:
			if (double d = prim(true))
			{
				left /= d;
				break;
			}
			return error("divide by 0");
		default:
			return left;
			break;
		}
	}
}

double nuber_value;
string string_value;
map<string, double> table;

double prim(bool get)
{
	if (get)
	{
		get_token();
	}
	switch (curr_tok)
	{
	case NUMBER:
		double v = nuber_value;
		get_token();
		return v;
	case NAME:
		double& v = table[string_value];
		if (get_token()==ASSIGN)
		{
			v = expr(true);
		}
		return v;
	case MINUS:
		return -prim(true);
	case LP:
		double e = expr(true);
		if (curr_tok!=RP)
		{
			return error("')' excepted");
		}
		get_token(); //skip ')'
		return e;
	default:
		return error("primary excepted");
	}
}
//error messages
double error(const string& s)
{
	cerr << "error: " << s << endl; //output stream for error messages 
	return 1;
}

Token_value get_token()
{
	char ch = 0;
	cin >> ch;
	switch (ch)
	{
	case 0:
		return curr_tok = END;
		break;
	case ';':
		return curr_tok = Token_value(ch);
		break;
	case '*':
		return curr_tok = Token_value(ch);
		break;
	case '/':
		return curr_tok = Token_value(ch);
		break;
	case '+':
		return curr_tok = Token_value(ch);
		break;
	case '-':
		return curr_tok = Token_value(ch);
		break;
	case '(':
		return curr_tok = Token_value(ch);
		break;
	case ')':
		return curr_tok = Token_value(ch);
		break;
	case '=':
		return curr_tok = Token_value(ch);
		break;
	case '0':
		cin.putback(ch);
		cin >> nuber_value;
		return curr_tok = NUMBER;
	case '1':
		cin.putback(ch);
		cin >> nuber_value;
		return curr_tok = NUMBER;
	case '2':
		cin.putback(ch);
		cin >> nuber_value;
		return curr_tok = NUMBER;
	case '3':
		cin.putback(ch);
		cin >> nuber_value;
		return curr_tok = NUMBER;
	case '4':
		cin.putback(ch);
		cin >> nuber_value;
		return curr_tok = NUMBER;
	case '5':
		cin.putback(ch);
		cin >> nuber_value;
		return curr_tok = NUMBER;
	case '6':
		cin.putback(ch);
		cin >> nuber_value;
		return curr_tok = NUMBER;
	case '7':
		cin.putback(ch);
		cin >> nuber_value;
		return curr_tok = NUMBER;
	case '8':
		cin.putback(ch);
		cin >> nuber_value;
		return curr_tok = NUMBER;
	case '9':
		cin.putback(ch);
		cin >> nuber_value;
		return curr_tok = NUMBER;
	default:
		if (isalpha(ch))
		{
			string_value = ch;
			while (cin.get(ch)&&isalnum(ch))
			{
				string_value.push_back(ch);
			}
			cin.putback(ch);
			return curr_tok = NAME;
		}
		error("bad token");
		curr_tok = PRINT;
	}
}
void main()
{
	table["pi"] = 3.1415926535897932385;
	table["å"] = 2.7182818284590452354;

	while (cin)
	{
		get_token();
		if (curr_tok == END) break;
		if (curr_tok == PRINT) continue;
		cout<< expr(false) << ' \n ';
	}
	
}