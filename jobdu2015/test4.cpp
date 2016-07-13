#include <stdio.h>
int main() {
	int hp, mp, boss;
	while (scanf("%d%d%d", &hp, &mp, &boss) != EOF) {
		int hh = 1;
		while (boss > 0 && hp > 0){
			int bossattack = hh % 5 == 0 ? 30 : 10;
			int bossattack2 = (hh + 1) % 5 == 0 ? 30 : 10;
			int bossattack3 = (hh + 2) % 5 == 0 ? 30 : 10;
			int youattack = 17;
			int magicattack = 60;
			if (mp >= 10) {
				mp -= 10;
				boss -= magicattack;
				if (boss <= 0) break;
				hp -= bossattack;
			}
			else if (mp >= 6) {
				if (boss <= youattack) {
					boss -= youattack;
					break;
				}
				else if (hp <= bossattack) {
					boss -= youattack;
					hp -= bossattack;
					break;
				}
				else {
					//now you can add mp safely
					mp += 4;
					hp -= bossattack;
				}
			}
			else if (mp >= 2) {
				if (boss <= youattack) {
					boss -= youattack;
					break;
				}
				else if (hp <= bossattack) {
					boss -= youattack;
					hp -= bossattack;
					break;
				}
				else if (boss <= youattack * 2) {
					boss -= youattack;
					hp -= bossattack;
				}
				else if (hp <= bossattack + bossattack2) {
					boss -= youattack;
					hp -= bossattack;
				}
				else {
					//now you can add mp safely
					mp += 4;
					hp -= bossattack;
				}
			}
			else {
				if (boss <= youattack) {
					boss -= youattack;
					break;
				}
				else if (hp <= bossattack) {
					boss -= youattack;
					hp -= bossattack;
					break;
				}
				else if (boss <= youattack * 2) {
					boss -= youattack;
					hp -= bossattack;
				}
				else if (hp <= bossattack + bossattack2) {
					boss -= youattack;
					hp -= bossattack;
				}
				else if (boss <= youattack * 3) {
					boss -= youattack;
					hp -= bossattack;
				}
				else if (hp <= bossattack + bossattack2 + bossattack3) {
					boss -= youattack;
					hp -= bossattack;
				}
				else {
					mp += 4;
					hp -= bossattack;
				}
			}
			hh++;
		}
		if (hp <= 0) {
			printf("-1\n");
		}
		else if (boss <= 0) {
			printf("%d\n", hh);
		}
	}
	return 0;
}