
import java.util.Scanner;

/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/**
 *
 * @author Md. Abdulla Al Mamun
 */
public class StepanAndVowels {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        StringBuilder str = new StringBuilder(sc.next());
        for(int i = 0; i < n; i++){
            if(isVowel(str.charAt(i))){
                int cnt = 1, j = i;
                while(j+1 < n && str.charAt(i) == str.charAt(j+1)){
                    cnt++;
                    j++;
                }
                if(cnt == 2 &&
                        (str.charAt(i) == 'e' || str.charAt(i) == 'o')){
                    for(int ii = 0; ii < 2; ii++)
                        System.out.print(str.charAt(i));
                }
                else{
                    System.out.print(str.charAt(i));
                }
                i = j;
            }
            else
                System.out.print(str.charAt(i));
        }
    }
    
    static boolean isVowel(char ch){
        return ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u' || ch == 'y';
    }
}
