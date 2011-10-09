#!/bin/bash
echo "-------------------------------------------------"
echo "                 Commit automatic                "
echo "-------------------------------------------------"
echo "- Deseja inserir algo no README?S/N             -"
read opcao
if [ opcao = S ]
then
	echo "- README:                                       -"
	read valor
	$valor > README
else
echo ""
fi

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


