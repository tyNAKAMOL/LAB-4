#include<stdio.h>
#include<conio.h>
#include<Windows.h>

void draw_ship() {
	printf("<-0->");
}
void gotoxy(int x, int y) {
	COORD c = { x, y };
	SetConsoleCursorPosition(
		GetStdHandle(STD_OUTPUT_HANDLE), c);
}
void erase_ship(int x, int y) {
	gotoxy(x, y);
	printf("     ");
}

int main() {
	char ch = ' ';
	int x = 10, y = 5;
	gotoxy(x, y);
	draw_ship();
	do {
		ch = _getch();
		if (ch == 97 && x > 0) {
			erase_ship(x, y);
			gotoxy(--x, y);
			draw_ship();

		}
		if (ch == 100 && x < 80) {
			erase_ship(x, y);
			gotoxy(++x, y);
			draw_ship();
		}
		if (ch == 119 && y > 0) {
			erase_ship(x, y);
			gotoxy(x, --y);
			draw_ship();
		}
		if (ch == 115 && y < 20) {
			erase_ship(x, y);
			gotoxy(x, ++y);
			draw_ship();
		} fflush(stdin);
		Sleep(100);
	} while (ch != 'x');
	return 0;
}