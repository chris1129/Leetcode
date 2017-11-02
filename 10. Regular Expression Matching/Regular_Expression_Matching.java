
public class Regular_Expression_Matching {
public boolean isMatch(String s, String p) {
        
        String text="0";
        text+=s;
        String pattern="0";
        pattern+=p;
        boolean T[][]=new boolean [text.length()][pattern.length()];
        //T[0][0]=true;
        for(int i=0;i<T.length;i++){
            for(int j=0;j<T[i].length;j++){
                if(i==0&&j==0)T[0][0]=true;
                else if((j-1)>-1&&(i-1)>-1&&(text.charAt(i)==pattern.charAt(j)||pattern.charAt(j)=='.'))T[i][j]=T[i-1][j-1];
                else if(pattern.charAt(j)=='*'){
                    
                     // zero occurance
                    if(j-2>-1&&T[i][j-2])T[i][j]=true;
                    else if(j-1>-1&&(pattern.charAt(j-1)==text.charAt(i))&&(T[i][j-1]==true||T[i-1][j]==true)){//a*  a=>zero occurance
                        T[i][j]=true;
                    }else if((j-1)>-1&&(i-1)>-1&&(pattern.charAt(j-1)=='.')&&((T[i-1][j-1]==true)||T[i-1][j]==true)){//.*
                        T[i][j]=true;
                    }
                    else{
                        T[i][j]=false;
                    }
                   
                    
                }
                //System.out.print(T[i][j]); 
            }
            
        }
        /*
        for(int i=0;i<T.length;i++){
            for(int j=0;j<T[i].length;j++)System.out.print(T[i][j]+"\t");
            System.out.println();
        }*/
        
        return T[text.length()-1][pattern.length()-1];
    }
}
