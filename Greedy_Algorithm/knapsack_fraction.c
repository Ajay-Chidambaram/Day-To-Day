#include <iostream>

using namespace std;

int main()
{
   
    int n,m;
    cin >> n >> m;
   
    int p[n], w[n], s[n];
    float kg[n], cmp = 1.00, f[n];;
   
    for(int i=0;i<n;i++)
        cin >> p[i];
        
    for(int i=0;i<n;i++)
        cin >> w[i];
        
    for(int i=0;i<n;i++)
    {
        s[i] = i;
        f[i] = 0;
        kg[i] = p[i]/(1.00*w[i]);
    }
    
    for(int i=0;i<n;i++)
        cout << kg[i] << " ";
   
    for(int i=0;i<n-1;i++)
    {
        for(int j=0;j<n-i-1;j++)
        {
            if(kg[j+1] > kg[j])
            {
                int temp = kg[j+1];
                kg[j+1] = kg[j];
                kg[j] = temp;
                
                temp = s[j+1];
                s[j+1] = s[j];
                s[j] = temp;
            }
        }
    }
    cout << endl;
    for(int i=0;i<n;i++)
        cout << kg[i] << "(" << s[i] << ")" << " ";
        
    int weight = 0, point = 0;
    
    cout << "while " << endl;
    while(weight != m && point < n)
    {
        weight = weight + w[s[point]];
        f[s[point]] = 1.00;
        if(weight > m)
        {
            weight = weight - w[s[point]];
            float index = (m - weight)/(1.00*w[s[point]]);
            weight = m;
            f[s[point]] = index;
        }
        cout << weight << endl;
        point++;
    }
    
    cout << endl;
    cout << endl;
    float sum = 0;
    for(int i=0;i<=point;i++)
        sum = sum + (f[i] * p[i]);
        //cout << f[i] << " "; 
        
    cout << "The maximum profit : " << sum << endl;
    return 0;
}
