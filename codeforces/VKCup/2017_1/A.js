var line = readline().split(' ');
var n = +line[0];
var c1 = +line[1];
var c2 = +line[1];
var s = readline();
var max;
var adult = 0;
var i;
for( i = 0; i < s.length ; i++) if(s[i] == '1') adult += 1;
print(adult);
while( Math.ceil((max + 2) / n ) <= adult &&
      (max + 1) * (max + 1) * c2 - (max) * (max) * c2 <= c1 ) max += 1;
max += 1;
print(max);
var sum = 0;
while(n >= max){
  sum += (c1 + c2 * (max - 1) * (max - 1));
  n -= max;
}
if(n > 0) sum += (c1 + c2 * (n) * (n));
print(sum);
