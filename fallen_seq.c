#include <stdio.h>
/*begin
write('Počet čísel: ');
read(N);
if N=0 then
  V:=0
else
  begin
  writeln('Posloupnost čísel:');
  for I:=1 to N do
    begin
    read(A[I]);
    B[I]:=1; C[I]:=0//
    end;
  V:=1
  end;

for I:=N-1 downto 1 do  {stanovení hodnot B[I], C[I]}
  for J:=I+1 to N do    {zkoumáme možnost navázání A[I]}
    if A[I] > A[J] then   {zde nastane jediný pokles}
      begin
      if C[I] < B[J]+1 then
        begin
        C[I]:=B[J]+1;
        if C[I] > V then V:=C[I]
        end
      end
    else                {zde lze navázat bez poklesu}
      begin
      if B[I] < B[J]+1 then
        begin
        B[I]:=B[J]+1;
        if B[I] > V then V:=B[I]
        end;
      if C[I] < C[J]+1 then
        begin
        C[I]:=C[J]+1;
        if C[I] > V then V:=C[I]
        end
      end;

writeln('Délka nejdelší vybrané podposloupnosti');
writeln('s nejvýše jedním poklesem: ',V)
end.*/
int nacti_cislo()
{
    int c = getchar();
    int znamenko = 1;
    if (c == '-')
    {
        znamenko = -1;
        c = getchar();
    }
    int num = 0;

    while (c >= '0' && c <= '9')
    {
        num = num * 10 + c - '0';
        c = getchar();
    }
    return num * znamenko;
}

int main()
{
    int a[10000], b[10000], c[10000];
    int N = nacti_cislo();
    for (int idx = 1; idx < N + 1; idx++)
    { // nacti N cisel
        a[idx] = nacti_cislo();
        b[idx] = 1;
        c[idx] = 0;
    }
    int V = 1;
    for (int i = N - 1; 0 < i; i--)
    {
        for (int j = i + 1; j <= N; j++)
        {
            if (a[i] > a[j])
            {
                if (c[i] < b[j] + 1)
                {
                    c[i] = b[j] + 1;
                    if (c[i] > V)
                    {
                        V = c[i];
                    }
                }
            }
            else
            {
                if (b[i] < b[j] + 1)
                {
                    b[i] = b[j] + 1;
                    if (b[i] > V)
                    {
                        V = b[i];
                    }
                }
                if (c[i] < c[j] + 1)
                {
                    c[i] = c[j] + 1;
                    if (c[i] > V)
                    {
                        V = c[i];
                    }
                }
            }
        }
    }
    printf("%d\n", V);
    return 0;
}