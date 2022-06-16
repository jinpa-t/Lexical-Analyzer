# Lexical-Analyzer (Course Project)
Given a linear equation tokenize the equation into lexemes and tokens.<br>
E.g. Input: <pre>y = 5x + 3</pre><br>

Output:<pre> y  -> identifier<br>
            =  -> Assign_OP<br>
            (  -> Open_Parenthesis<br>
            2  -> int_literal<br>
            *  -> Mult_OP<br>
            x  -> identifier<br>
            )  -> Close_Parenthesis<br>
            +  -> Add_OP<br>
            50.00  -> int_literal<br>
            ;  -> End_Marker<br></pre>
