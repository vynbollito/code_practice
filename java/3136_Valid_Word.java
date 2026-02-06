/*
It contains a minimum of 3 characters.
It consists of the digits 0-9, and the uppercase and lowercase English letters. (Not necessary to have all of them.)
It includes at least one vowel.
It includes at least one consonant.

Constraints:
1 <= word.length <= 20
word consists of English uppercase and lowercase letters, digits. Not '@', '#', and '$'.

*/
class ValidWord3136 {
    
    public boolean getvowCons(int size, String word){
        int i               = 0;
        boolean vowel       = false;   
        boolean consonant   = false;
        boolean special     = false;
        
        while( i < size && special == false){
            char aux_char = word.charAt(i);

            if( aux_char == '@' || aux_char == '#' || aux_char == '$')
                 return false;
            else {
                aux_char = Character.toLowerCase(aux_char);
                       
               if( aux_char == 'a' || aux_char == 'e' || aux_char == 'i' || aux_char == 'o' || aux_char == 'u' )
                   vowel = true;
                else if( !( aux_char >= '0' && aux_char <= '9') ) 
                    consonant = true; 
            }
            i++;
        }
        if( vowel == true && consonant == true )
            return true;  
        return false;
    }
       
    public boolean isValid(String word) {
        int size = word.length();
        
           if(size >= 3 ){
            if(getvowCons(size, word) == true)
                return true;     
           }
        return false;
    }
    
    public static void main(String[] args){
        ValidWord3136 solution = new ValidWord3136();
        System.out.println("main: "+ solution.isValid("AhI"));
    }
}