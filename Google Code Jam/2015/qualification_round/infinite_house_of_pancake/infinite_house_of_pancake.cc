#include <cstdio>
//#include <cstring>
#include <map>
//#include <algorithm>
//#include <vector>
using namespace std;

int main() {
  int T, D;
  int i, j, k;
  int tmp, mins/*, numOfDiners*/, acc;
  scanf("%d", &T);
  for (i = 1; i <= T; i++) {
    map<int, int> plate2diner;
    scanf("%d", &D);
    //numOfDiners = D;
    acc = 0;
    for (j = 0; j < D; j++) {
      scanf("%d", &tmp);
      plate2diner[tmp]++;
      //
      printf("%d ", tmp);
    }
    mins = plate2diner.rbegin()->first;
    for (auto x = plate2diner.rbegin(); x != plate2diner.rend(); x++) {
      //printf("%d\n", x->first);
      acc += x->second;
      if (acc > mins)
        break;
      int tmin = acc;
      plate2diner[x->first / 2] += x->second;
      plate2diner[x->first - x->first / 2] += x->second;
      auto pre = x;
      pre++;
      if (pre != plate2diner.rend()) {
        tmin += pre->first;
      }
      if (tmin < mins)
        mins = tmin;
    }
    printf("\n");
    printf("Case #%d: %d\n", i, mins);
  }
}
