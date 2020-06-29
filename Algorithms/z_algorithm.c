/************************************************************
             Z-ALGORITHM FOR PATTERN MATCHING
 ***********************************************************/

#include<stdio.h>
#include<string.h>

int* calculate_z(char s[])
{
      int len = strlen(s);
      int right = 0, left = 0;
      static int z[1000];

      z[0] = 0;

      for(int i=1;i<len;i++)
      {
            if(i > right)
            {
                  left = right = i;
                  while(right < len && (s[right] == s[right-left]))
                  {
                        right++;
                  }
                  z[i] = right - left;
                  right--;
            }
            else
            {
                  int k1 = i - left;
                  if(z[k1] < right - i + 1)
                        z[i] = z[k1];
                  else
                  {
                        left = i;
                        while(right < len && (s[right] == s[right-left]))
                        {
                              right++;
                        }
                        z[i] = right - left;
                        right--;
                  } 
            }  
      }

      return z;
}

int z_algo(char s[], char p[])
{
      int len1 = strlen(s);
      int len2 = strlen(p);
      int count = 0;

      p[len2] = '$';
      strcat(p,s);
      int* z = calculate_z(p);
      int new_len = strlen(p);

      for(int i=0;i<new_len;i++)
            printf("%c ",p[i]);

      printf("\n");
      for(int i=0;i<new_len;i++)
      {
            printf("%d ",z[i]);
            if(z[i] == len2)
                  count++;
      }
      printf("\n");

      return count;
}

int main()
{
      char s[1000] = "aabaabaabaxxaab";
      char p[1000] = "aab";

      int count = z_algo(s,p);
      printf("\nNumber of occurence of pattern string in an given string : %d",count);
}