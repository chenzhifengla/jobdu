/*
#include <stdio.h>
#include <algorithm>
using namespace std;
struct gasstation {
	double price;
	double distance;
	bool operator < (const gasstation &b) const {
		return distance < b.distance;
	}
}buf[510];
int main() {
	double cmax, dis, davg;
	int n;
	while (scanf("%lf%lf%lf%d", &cmax, &dis, &davg, &n) != EOF) {
		for (int i = 0; i < n; i++) {
			scanf("%lf%lf", &buf[i].price, &buf[i].distance);
		}
		sort(buf, buf + n);
		double pos = 0;	//ths car's position
		double cap = 0;	//the car's tank cap
		int flag = 1;	//can the car arrvie the next station
		double pricesum = 0;
		double dmax = cmax * davg;
		if (buf[0].distance != 0) {
			flag = -1;
		}
		else {
			for (int i = 0; i < n - 1; i++) {
				if ((buf[i + 1].distance - pos) >dmax) {
					//cannot arrive the next station
					flag = 0;
					break;
				}
				else {
					int flag2 = 1;	//add the fuel fully in this station
					for (int j = i + 1; j < n; j++) {
						if ((buf[j].distance - pos) > dmax) {
							break;
						}
						if (buf[j].price <= buf[i].price) {
							flag2 = 0;	//add fuel in the next station
							break;
						}
					}
					double capneed = (buf[i + 1].distance - buf[i].distance) / davg;
					if (flag2 == 0) {
						//add some gas to arrvie the next station
						if (cap >= capneed) {
							//cap is enough
							cap -= capneed;
							pos = buf[i + 1].distance;
						}
						else {
							//cap is not enough
							pos = buf[i + 1].distance;
							pricesum += (capneed - cap) * buf[i].price;
							cap = 0;
						}
					}
					else {
						//add gas in this station
						if (cap < cmax) {
							pricesum += (cmax - cap) * buf[i].price;
							cap = cmax - capneed;
							pos = buf[i + 1].distance;
						}
					}
				}
			}
			//now the car is in the last station
			//can we arrive the destination
			if (flag == 1) {
				if ((dis - pos) > dmax) {
					flag = 0;
				}
			}
		}
		if (flag == -1) {
			printf("The maximum travel distance = 0.00\n");
		}
		else if (flag == 0) {
			printf("The maximum travel distance = %.2lf\n", pos + dmax);
		}
		else {
			double capneed = (dis - pos) / davg;
			if (cap < capneed) {
				//cap is not enough
				pricesum += (capneed - cap) * buf[n - 1].price;
			}
			printf("%.2lf\n", pricesum);
		}
	}
	return 0;
}
*/

#include <stdio.h>
#include <algorithm>
using namespace std;
struct gasstation {
	double pos;
	double price;
	double oil;
}buf[510];
bool cmpprice(gasstation a, gasstation b) {
	return a.price < b.price;
}
bool cmppos(gasstation a, gasstation b) {
	return a.pos < b.pos;
}
int main() {
	double cmax, dis, davg;
	int n;
	while (scanf("%lf%lf%lf%d", &cmax, &dis, &davg) != EOF) {
		for (int i = 0; i < n; i++) {
			scanf("%lf%lf", &buf[i].price, &buf[i].pos);
		}
		sort(buf, buf + n, cmpprice);

	}
}