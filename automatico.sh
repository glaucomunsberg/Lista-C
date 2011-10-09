#!/bin/bash
echo "-------------------------------------------------"
echo "                      GITHUB                     "
echo "-------------------------------------------------"
echo "Commit ou Push?				      -"
read coup
if [ "C" = "$coup" ]; then
	echo "- Deseja inserir algo no README?S/N             -"
	read opcao
	#
	if [ "S" = "$opcao" ]; then
		gedit README
		git add README
	fi
	#
	echo "- Carregando os arquivos...                     -"
	git add *.*
	echo "- Insira o nome do commit:                      -"
	read nome
	git commit -m $nome
	echo "- Commintando...                                -"
	git remote add origin git@github.com:glaucomunsberg/PHP.git
	git push origin master
	echo "-                  Commitado!                   -"
	echo "-------------------------------------------------"
else
	echo "Push... 					      -"
	git remote add origin git@github.com:glaucomunsberg/PHP.git
	git push origin master
	echo "-                  Push!	                      -"
	echo "-------------------------------------------------"
fi
