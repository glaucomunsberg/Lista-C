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
		nano README
		git add README
	fi
	#
	echo "- Carregando os arquivos...                     -"
	git add *.*
	echo "- Insira o nome do commit:                      -"
	read nome
	git commit -m ${nome// /_}
	clear
	echo "- Commintando...                                -"
	git remote add origin git@github.com:glaucomunsberg/PHP.git
	git push origin master
	echo "-------------------------------------------------"
	echo "-                  Commitado!                   -"
	echo "-------------------------------------------------"
else
	echo "-------------------------------------------------"
	echo "1- Resetar SSH service"
	echo "2- Git Pull"
	read outros
	case $outros in
		1) 	clear;
			echo "-------------------------------------------------";
			echo "- Resetando SSH...                              -";
			sudo systemctl restart sshd.service;
			sleep 1;
			sudo ssh -T git@github.com
			sleep 1;
			echo "-------------------------------------------------";;
		2) 	clear;
			echo "-------------------------------------------------";
			echo "- Github Pull...                                -";
			git remote add drnic git://github.com/glaucomunsber/PHP.git
			git pull
			sleep 1;
			echo "-------------------------------------------------";;
		3) 	clear;
			echo "-------------------------------------------------";
			echo "- Teste de Conexão..                            -";
			sudo ssh -T git@github.com
			sleep 1;
			echo "-------------------------------------------------";;
		*) echo "Saindo...";sleep 1;echo "";;
	esac
	clear

fi
