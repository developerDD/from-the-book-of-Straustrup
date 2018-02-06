#include<iostream>
#include<vector>
#include<map>
#include<string>

using namespace std;

//
enum Token_value 
{
	NAME, NUMBER, END, PLUS = '+', MINUS = '-', MUL = '*', DIV = '/', PRINT = ';', ASSIGN = '=', LP = '(', RP = ')'
};
Token_value curr_tok = PRINT;
//addition/subtraction
double term(bool);
double prim(bool);
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
				left / d;
				break;
			}
			return error("divide by 0");
		default:
			return left;
			break;
		}
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
		}
}
void main()
{

}