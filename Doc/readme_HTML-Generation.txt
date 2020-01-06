Steps for building html help:

1) Create block in Scilab (make sure "createBlockDocu.sci" gets executed -> check createXcosBlock.sci script, if not)
  --> ideally, this would produce the html help. Right now, this does not work, so following steps are also necessary

2) copy htlatexconfig.cfg from <X2C_ROOT>/Documentation/General/Styles to <X2C_ROOT>/Library/<LIB_NAME>/Doc

3) execute in bash: htlatex <BLOCK_NAME>_.tex "htlatexconfig,html,png"
  (tex4ht is required for that command to work)
 
