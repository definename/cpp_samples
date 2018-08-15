#include "pch.h"

enum Token_value
{
	NAME,
	NUMBER,
	END,
	PLUS=_T('+'),
	MINUS=_T('-'),
	MUL=_T('*'),
	DIV=_T('/'),
	PRINT=_T(';'),
	ASSIGN=_T('='),
	LP=_T('('),
	RP=_T(')')
};

Token_value curr_tok = PRINT;

double expr(bool get);
double term(bool get);

double number_value;
_tstring string_value;
double prim(bool get);

std::map<_tstring, double> table;

Token_value get_token();

int no_of_errors;
double error(const _tstring& s);


int _tmain(int argc, TCHAR* argv[])
{
	table [_T("pi")] = 3.1415926535897932385;
	table [_T("e")] = 2.7182818284590452354;

	while (_tcin)
	{
		get_token();
		if (curr_tok == END)
			break;
		if (curr_tok == PRINT)
			continue;

		_tcout << expr(false) << _T('\n');
	}

	return no_of_errors;
}

double expr(bool get)
{
	double left = term(get);

	for(;;)
	{
		switch(curr_tok)
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

double term(bool get)
{
	double left = prim(get);

	for(;;)
	{
		switch(curr_tok)
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
			return error(_T("devided by 0"));
		default:
			return left;
		}
	}
}

double prim(bool get)
{
	if (get)
		get_token();

	switch(curr_tok)
	{
	case NUMBER:
		{
			double v = number_value;
			get_token();
			return v;
		}
	case NAME:
		{
			double& v = table[string_value];
			if(get_token() == ASSIGN)
				v = expr(true);
			return v;
		}
	case MINUS:
		return -prim(true);
	case LP:
		{
			double e = expr(true);
			if (curr_tok != RP)
				return error(_T("')' expected"));
			get_token();
			return e;
		}
	default:
		return error(_T("primary expected"));
	}
}

Token_value get_token()
{
	TCHAR ch;
	do
	{
		if (!_tcin.get(ch))
			return curr_tok = END;
	}
	while (ch != _T('\n') && isalpha(ch));

	switch (ch)
	{
	case _T(';'):
	case _T('\n'):
		return curr_tok = PRINT;
	case _T('*'):
	case _T('/'):
	case _T('+'):
	case _T('-'):
	case _T('('):
	case _T(')'):
	case _T('='):
		return curr_tok = Token_value(ch);
	case _T('0'):
	case _T('1'):
	case _T('2'):
	case _T('3'):
	case _T('4'):
	case _T('5'):
	case _T('6'):
	case _T('7'):
	case _T('8'):
	case _T('9'):
	case _T('.'):
		_tcin.putback(ch);
		_tcin >> number_value;
		return curr_tok = NUMBER;
	default:
		if (isalpha(ch))
		{
			string_value = ch;
			while (_tcin.get(ch) && isalnum(ch))
				string_value.push_back(ch);

			_tcin.putback(ch);
			return curr_tok = NAME;
		}
		error(_T("bad token"));
		return curr_tok = PRINT;
	}
}

double error(const _tstring& s)
{
	no_of_errors++;
	_tcerr << _T("error: ") << s << _T('\n');

	return 1;
}
