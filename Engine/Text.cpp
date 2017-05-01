#include "Text.h"

Text::Text(Graphics & in_gfx)
	:gfx(in_gfx)
{
	Reset();
}

void Text::Reset()
{
	c = Colors::White;
	pos = {0,0};
	box1 = {0,0};
	box2 = {gfx.ScreenWidth-1, gfx.ScreenHeight-1};
	text = "";
	spacing = 25 + 5;
	lineSpacing = 30 + 5;
}

void Text::SetPostion(int in_x, int in_y)
{
	pos.x = in_x;
	pos.y = in_y;
}

void Text::SetColor(Color in_c)
{
	c = in_c;
}

void Text::SetColor(int r, int g, int b)
{
	c = {unsigned char(r), unsigned char(g), unsigned char(b)};
}

void Text::SetBoxSize(int x1, int y1, int x2, int y2)
{
	box1.x = x1;
	box1.y = y1;
	box2.x = x2;
	box2.y = y2;
	if (x1 < 0) box1.x = 0;
	if (y1 < 0) box1.y = 0;
	if (x2 >= gfx.ScreenWidth) box2.x = gfx.ScreenWidth - 1;
	if (y2 >= gfx.ScreenHeight) box2.y = gfx.ScreenHeight - 1;
}

void Text::SetSpacing(int in_spacing)
{
	spacing = 25 + in_spacing;
}

void Text::SetLineSpacing(int in_lineSpacing)
{
	lineSpacing = 30 + in_lineSpacing;
}

void Text::SetText(std::string in_text)
{
	text = in_text;
	for (auto& c : text) c = toupper(c);
}

void Text::Draw()
{
	Position PosOld = pos;
	int Column = 0;
	int Row = 0;
	for (auto& ch : text)
	{
		if (!(pos.x < box2.x - 2* spacing))
		{
			Column = 0;
			Row++;
		}
		pos.x = box1.x + PosOld.x + Column * spacing;
		pos.y = box1.y + PosOld.y + Row * lineSpacing;
		if (ch == '\n')
		{
			Column = -1;
			Row++;
		}
		else
		{
			if(pos.y < box2.y - lineSpacing)
			DrawCh(ch);
		}
		Column++;
	}
	pos = PosOld;
}

void Text::DrawCh(char ch)
{
	switch (ch)
	{
		case 'A':
			gfx.chA(pos.x, pos.y, c);
			break;
		case 'B':
			gfx.chB(pos.x, pos.y, c);
			break;
		case 'C':
			gfx.chC(pos.x, pos.y, c);
			break;
		case 'D':
			gfx.chD(pos.x, pos.y, c);
			break;
		case 'E':
			gfx.chE(pos.x, pos.y, c);
			break;
		case 'F':
			gfx.chF(pos.x, pos.y, c);
			break;
		case 'G':
			gfx.chG(pos.x, pos.y, c);
			break;
		case 'H':
			gfx.chH(pos.x, pos.y, c);
			break;
		case 'I':
			gfx.chI(pos.x, pos.y, c);
			break;
		case 'J':
			gfx.chJ(pos.x, pos.y, c);
			break;
		case 'K':
			gfx.chK(pos.x, pos.y, c);
			break;
		case 'L':
			gfx.chL(pos.x, pos.y, c);
			break;
		case 'M':
			gfx.chM(pos.x, pos.y, c);
			break;
		case 'N':
			gfx.chN(pos.x, pos.y, c);
			break;
		case 'O':
			gfx.chO(pos.x, pos.y, c);
			break;
		case 'P':
			gfx.chP(pos.x, pos.y, c);
			break;
		case 'Q':
			gfx.chQ(pos.x, pos.y, c);
			break;
		case 'R':
			gfx.chR(pos.x, pos.y, c);
			break;
		case 'S':
			gfx.chS(pos.x, pos.y, c);
			break;
		case 'T':
			gfx.chT(pos.x, pos.y, c);
			break;
		case 'U':
			gfx.chU(pos.x, pos.y, c);
			break;
		case 'V':
			gfx.chV(pos.x, pos.y, c);
			break;
		case 'W':
			gfx.chW(pos.x, pos.y, c);
			break;
		case 'X':
			gfx.chX(pos.x, pos.y, c);
			break;
		case 'Y':
			gfx.chY(pos.x, pos.y, c);
			break;
		case 'Z':
			gfx.chZ(pos.x, pos.y, c);
			break;
		case '0':
			gfx.ch0(pos.x, pos.y, c);
			break;
		case '1':
			gfx.ch1(pos.x, pos.y, c);
			break;
		case '2':
			gfx.ch2(pos.x, pos.y, c);
			break;
		case '3':
			gfx.ch3(pos.x, pos.y, c);
			break;
		case '4':
			gfx.ch4(pos.x, pos.y, c);
			break;
		case '5':
			gfx.ch5(pos.x, pos.y, c);
			break;
		case '6':
			gfx.ch6(pos.x, pos.y, c);
			break;
		case '7':
			gfx.ch7(pos.x, pos.y, c);
			break;
		case '8':
			gfx.ch8(pos.x, pos.y, c);
			break;
		case '9':
			gfx.ch9(pos.x, pos.y, c);
			break;
		case '.':
			gfx.chDot(pos.x, pos.y, c);
			break;
		case ',':
			gfx.chComma(pos.x, pos.y, c);
			break;
		case '\'':
			gfx.chApostrophe(pos.x, pos.y, c);
			break;
		case '!':
			gfx.chExMark(pos.x, pos.y, c);
			break;
		case '?':
			gfx.chQMark(pos.x, pos.y, c);
			break;
		case '-':
			gfx.chDash(pos.x, pos.y, c);
			break;
	}
}
