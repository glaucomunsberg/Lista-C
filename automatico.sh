#!/bin/bash
start=true
while [ $start = true ]; do
	clear
	echo "-------------------------------------------------"
	echo "                      GITHUB                     "
	echo "-------------------------------------------------"
	echo "1- Commitar                                     -"
	echo "2- Opções                                       -"
	echo "0- Sair                                         -"
	read commitar
	if [ "1" = "$commitar" ]; then
		echo "- Deseja inserir algo no README? S/N            -"
		read opcao
		#
		if [ "S" = "$opcao" ]; then
			nano README
			git add README
		fi
		#
		echo "- Carregando os arquivos...                     -"
		git add *.*
		git add README
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
		read nada
	else
		if [ "0" = "$commitar" ]; then
			clear
			echo "-------------------------------------------------";
			echo "                      GITHUB                     ";
			echo "-------------------------------------------------";
			echo "- Saindo...                                     -";
			sleep 1;
			clear;
			exit;
		fi
		clear
		echo "-------------------------------------------------"
		echo "                      GITHUB                     "
		echo "-------------------------------------------------"
		echo "1- Resetar SSH service                          -"
		echo "2- Git Pull                                     -"
		echo "3- Testa de conexão                             -"
		echo "4- Status                                       -"
		echo "0- Sair                                         -"
		read outros
		case $outros in
			1) 	clear;
				echo "-------------------------------------------------";
				echo "- Resetando SSH...                              -";
				sudo systemctl restart sshd.service;
				sleep 1;
				sudo ssh -T git@github.com
				echo "-------------------------------------------------";
				read outros;;
			2) 	clear;
				echo "-------------------------------------------------";
				echo "- Github Pull...                                -";
				git remote add drnic git://github.com/glaucomunsber/PHP.git
				git pull
				echo "-------------------------------------------------";
				read outros;;
			3) 	clear;
				echo "-------------------------------------------------";
				echo "- Teste de Conexão..                            -";
				sudo ssh -T git@github.com
				echo "-------------------------------------------------";
				read outros;;
			4) 	clear;
				echo "-------------------------------------------------";
				echo "- Status...                                     -";
				sudo git status
				echo "-------------------------------------------------";
				read outros;;
			0) 
				clear
				echo "-------------------------------------------------";
				echo "                      GITHUB                     ";
				echo "-------------------------------------------------";
				echo "- Saindo...                                     -";
				sleep 1;
				clear;
				exit;;
		esac

	fi
done
