evali "$(ssh-agent -s)" 
ssh-add ~/.ssh/git_siwolee
git add .
git commit -m ".."
git push origin main
