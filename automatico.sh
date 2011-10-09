#!/bin/bash
echo "Commit automático"
git add *.*
echo "Insira o nome do commit:"
read nome
git commit -m '$nome'
echo "Commintando..."
git remote add origin git@github.com:glaucomunsberg/PHP.git
git push origin master
echo "Commitado!"



