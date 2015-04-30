#!/bin/sh

#creation arboresence
rm -Rf A >/dev/null 2>&1
mkdir A >/dev/null 2>&1
touch A/qwe  >/dev/null 2>&1
touch A/wer  >/dev/null 2>&1
touch A/ert  >/dev/null 2>&1
touch A/.asd >/dev/null 2>&1
touch A/.mkj  >/dev/null 2>&1

dd bs=1 count=100 if=/dev/random of=A/qwe  >/dev/null 2>&1
dd bs=2 count=100 if=/dev/random of=A/wer  >/dev/null 2>&1
dd bs=1 count=103 if=/dev/random of=A/.asd >/dev/null 2>&1
dd bs=25 count=100 if=/dev/random of=A/.mkj  >/dev/null 2>&1

ln -s A/qwe A/lnk >/dev/null 2>&1
ln -s A/.asd A/nhj  >/dev/null 2>&1
ln -s A/nhj A/nnas  >/dev/null 2>&1


mkdir A/.CD  >/dev/null 2>&1
mkdir A/.POK  >/dev/null 2>&1
mkdir A/.GGF >/dev/null 2>&1
mkdir A/YYT  >/dev/null 2>&1
mkdir A/FFD >/dev/null 2>&1

touch A/.CD/qwe >/dev/null 2>&1
touch A/.CD/wer  >/dev/null 2>&1
touch A/.CD/ert  >/dev/null 2>&1
touch A/.CD/.asd >/dev/null 2>&1
touch A/.CD/.mkj  >/dev/null 2>&1

dd bs=1 count=160 if=/dev/random of=A/.CD/qwe  >/dev/null 2>&1
dd bs=2 count=14450 if=/dev/random of=A/.CD/wer  >/dev/null 2>&1
dd bs=1 count=1353 if=/dev/random of=A/.CD/.asd  >/dev/null 2>&1
dd bs=25 count=1045 if=/dev/random of=A/.CD/.mkj  >/dev/null 2>&1

ln -s A/.CD/qwe A/.CD/lnk  >/dev/null 2>&1
ln -s A/.CD/.asd A/.CD/nhj >/dev/null 2>&1
ln -s A/.CD/nhj A/.CD/nnas  >/dev/null 2>&1


mkdir A/.CD/.tgt  >/dev/null 2>&1
mkdir A/.CD/.IIU  >/dev/null 2>&1
mkdir A/.CD/SDFD  >/dev/null 2>&1
mkdir A/.CD/KKO  >/dev/null 2>&1

touch A/.CD/.tgt/ggf  >/dev/null 2>&1
touch A/.CD/.tgt/.ddf  >/dev/null 2>&1

touch A/.CD/SDFD/asdc >/dev/null 2>&1
touch A/.CD/KKO/.xcvv  >/dev/null 2>&1
touch A/.CD/SDFD/vgbh  >/dev/null 2>&1
touch A/.CD/KKO/.nhnjm  >/dev/null 2>&1

touch A/.CD/SDFD/asdc >/dev/null 2>&1
touch A/.CD/KKO/.xcvv  >/dev/null 2>&1
touch A/.CD/SDFD/vgbh >/dev/null 2>&1
touch A/.CD/KKO/.nhnjm >/dev/null 2>&1

dd bs=1 count=15630 if=/dev/random of=A/.CD/SDFD/asdc  >/dev/null 2>&1
dd bs=1 count=1450 if=/dev/random of=A/.CD/KKO/.xcvv  >/dev/null 2>&1
dd bs=1 count=15360 if=/dev/random of=A/.CD/SDFD/vgbh  >/dev/null 2>&1
dd bs=1 count=1560 if=/dev/random of=A/.CD/KKO/.nhnjm  >/dev/null 2>&1

dd bs=1 count=1450 if=/dev/random of=A/.CD/.tgt/ggf  >/dev/null 2>&1
dd bs=2 count=130 if=/dev/random of=A/.CD/.tgt/.ddf  >/dev/null 2>&1

touch A/.CD/.IIU/ggf  >/dev/null 2>&1
touch A/.CD/.IIU/.ddf >/dev/null 2>&1
mkdir A/.CD/.IIU/KKK  >/dev/null 2>&1
touch A/.CD/.IIU/KKK/.sadf  2>/dev/null 2>&1
mkdir A/.CD/.IIU/NNBG  >/dev/null 2>&1
touch A/.CD/.IIU/NNBG/dvfv  >/dev/null 2>&1

touch A/.CD/SDFD/qwe >/dev/null 2>&1
touch A/.CD/SDFD/wer  >/dev/null 2>&1
touch A/.CD/SDFD/ert  >/dev/null 2>&1
touch A/.CD/SDFD/.asd  >/dev/null 2>&1
touch A/.CD/SDFD/.mkj  >/dev/null 2>&1

dd bs=1 count=10 if=/dev/random of=A/.CD/SDFD/qwe  >/dev/null 2>&1
dd bs=2 count=10 if=/dev/random of=A/.CD/SDFD/wer >/dev/null 2>&1
dd bs=1 count=13 if=/dev/random of=A/.CD/SDFD/.asd  >/dev/null 2>&1
dd bs=25 count=10 if=/dev/random of=A/.CD/SDFD/.mkj >/dev/null 2>&1

#tests simples
ls -1 > /var/tmp/ls.out
./ft_ls > /var/tmp/ft_ls.out
diff /var/tmp/ls.out /var/tmp/ft_ls.out | wc -l | sed -e "s/ //g" > /var/tmp/result_ls

ls -1 . > /var/tmp/ls.out
./ft_ls . > /var/tmp/ft_ls.out
diff /var/tmp/ls.out /var/tmp/ft_ls.out | wc -l | sed -e "s/ //g" >> /var/tmp/result_ls

ls -1 ./ > /var/tmp/ls.out
./ft_ls ./ > /var/tmp/ft_ls.out
diff /var/tmp/ls.out /var/tmp/ft_ls.out | wc -l | sed -e "s/ //g" >> /var/tmp/result_ls

ls -1 ./ . > /var/tmp/ls.out
./ft_ls ./ .> /var/tmp/ft_ls.out
diff /var/tmp/ls.out /var/tmp/ft_ls.out | wc -l | sed -e "s/ //g" >> /var/tmp/result_ls

echo "Tests simple : "
echo "-> OK  \c"
cat /var/tmp/result_ls | grep "0" | wc -l | sed -e "s/ //g"
echo "-> NOK \c"
cat /var/tmp/result_ls | grep -v "0" | wc -l | sed -e "s/ //g"

ls -1 -R > /var/tmp/ls.out 2>/var/tmp/lserr.out
./ft_ls -R > /var/tmp/ft_ls.out 2>/var/tmp/ft_lserr.out
diff /var/tmp/ls.out /var/tmp/ft_ls.out | wc -l | sed -e "s/ //g" > /var/tmp/result_ls
diff /var/tmp/lserr.out /var/tmp/ft_lserr.out | wc -l | sed -e "s/ //g" >> /var/tmp/result_ls


ls -l > /var/tmp/ls.out 2>/var/tmp/lserr.out
./ft_ls -l > /var/tmp/ft_ls.out 2>/var/tmp/ft_lserr.out
diff /var/tmp/ls.out /var/tmp/ft_ls.out | wc -l | sed -e "s/ //g" >> /var/tmp/result_ls
diff /var/tmp/lserr.out /var/tmp/ft_lserr.out | wc -l | sed -e "s/ //g" >> /var/tmp/result_ls


ls -1 -r >/var/tmp/ls.out 2>/var/tmp/lserr.out
./ft_ls -r > /var/tmp/ft_ls.out 2>/var/tmp/ft_lserr.out
diff /var/tmp/ls.out /var/tmp/ft_ls.out | wc -l | sed -e "s/ //g" >> /var/tmp/result_ls
diff /var/tmp/lserr.out /var/tmp/ft_lserr.out | wc -l | sed -e "s/ //g" >> /var/tmp/result_ls


ls -1 -t > /var/tmp/ls.out 2>/var/tmp/lserr.out
./ft_ls -t > /var/tmp/ft_ls.out 2>/var/tmp/ft_lserr.out
diff /var/tmp/ls.out /var/tmp/ft_ls.out | wc -l | sed -e "s/ //g" >> /var/tmp/result_ls
diff /var/tmp/lserr.out /var/tmp/ft_lserr.out | wc -l | sed -e "s/ //g" >> /var/tmp/result_ls


ls -1 -a >/var/tmp/ls.out 2>/var/tmp/lserr.out
./ft_ls -a > /var/tmp/ft_ls.out 2>/var/tmp/ft_lserr.out
diff /var/tmp/ls.out /var/tmp/ft_ls.out | wc -l | sed -e "s/ //g" >> /var/tmp/result_ls
diff /var/tmp/lserr.out /var/tmp/ft_lserr.out | wc -l | sed -e "s/ //g" >> /var/tmp/result_ls


ls -la > /var/tmp/ls.out 2>/var/tmp/lserr.out
./ft_ls -la > /var/tmp/ft_ls.out 2>/var/tmp/ft_lserr.out
diff /var/tmp/ls.out /var/tmp/ft_ls.out | wc -l | sed -e "s/ //g" >> /var/tmp/result_ls
diff /var/tmp/lserr.out /var/tmp/ft_lserr.out | wc -l | sed -e "s/ //g" >> /var/tmp/result_ls


ls -1 -ar > /var/tmp/ls.out 2>/var/tmp/lserr.out
./ft_ls -ar > /var/tmp/ft_ls.out 2>/var/tmp/ft_lserr.out
diff /var/tmp/ls.out /var/tmp/ft_ls.out | wc -l | sed -e "s/ //g" >> /var/tmp/result_ls
diff /var/tmp/lserr.out /var/tmp/ft_lserr.out | wc -l | sed -e "s/ //g" >> /var/tmp/result_ls



ls -1 -at > /var/tmp/ls.out 2>/var/tmp/lserr.out
./ft_ls -at > /var/tmp/ft_ls.out 2>/var/tmp/ft_lserr.out
diff /var/tmp/ls.out /var/tmp/ft_ls.out | wc -l | sed -e "s/ //g" >> /var/tmp/result_ls
diff /var/tmp/lserr.out /var/tmp/ft_lserr.out | wc -l | sed -e "s/ //g" >> /var/tmp/result_ls


ls -1 -rt > /var/tmp/ls.out 2>/var/tmp/lserr.out
./ft_ls -rt > /var/tmp/ft_ls.out 2>/var/tmp/ft_lserr.out
diff /var/tmp/ls.out /var/tmp/ft_ls.out | wc -l | sed -e "s/ //g" >> /var/tmp/result_ls
diff /var/tmp/lserr.out /var/tmp/ft_lserr.out | wc -l | sed -e "s/ //g" >> /var/tmp/result_ls


ls -rl > /var/tmp/ls.out 2>/var/tmp/lserr.out
./ft_ls -rl > /var/tmp/ft_ls.out 2>/var/tmp/ft_lserr.out
diff /var/tmp/ls.out /var/tmp/ft_ls.out | wc -l | sed -e "s/ //g" >> /var/tmp/result_ls
diff /var/tmp/lserr.out /var/tmp/ft_lserr.out | wc -l | sed -e "s/ //g" >> /var/tmp/result_ls


ls -tl > /var/tmp/ls.out 2>/var/tmp/lserr.out
./ft_ls -tl > /var/tmp/ft_ls.out 2>/var/tmp/ft_lserr.out
diff /var/tmp/ls.out /var/tmp/ft_ls.out | wc -l | sed -e "s/ //g" >> /var/tmp/result_ls
diff /var/tmp/lserr.out /var/tmp/ft_lserr.out | wc -l | sed -e "s/ //g" >> /var/tmp/result_ls



ls -1 -Ra > /var/tmp/ls.out 2>/var/tmp/lserr.out
./ft_ls -Ra > /var/tmp/ft_ls.out 2>/var/tmp/ft_lserr.out
diff /var/tmp/ls.out /var/tmp/ft_ls.out | wc -l | sed -e "s/ //g" >> /var/tmp/result_ls
diff /var/tmp/lserr.out /var/tmp/ft_lserr.out | wc -l | sed -e "s/ //g" >> /var/tmp/result_ls


ls -1 -Rt > /var/tmp/ls.out 2>/var/tmp/lserr.out
./ft_ls -Rt > /var/tmp/ft_ls.out 2>/var/tmp/ft_lserr.out
diff /var/tmp/ls.out /var/tmp/ft_ls.out | wc -l | sed -e "s/ //g" >> /var/tmp/result_ls
diff /var/tmp/lserr.out /var/tmp/ft_lserr.out | wc -l | sed -e "s/ //g" >> /var/tmp/result_ls


ls -Rl > /var/tmp/ls.out 2>/var/tmp/lserr.out
./ft_ls -Rl > /var/tmp/ft_ls.out 2>/var/tmp/ft_lserr.out
diff /var/tmp/ls.out /var/tmp/ft_ls.out | wc -l | sed -e "s/ //g" >> /var/tmp/result_ls
diff /var/tmp/lserr.out /var/tmp/ft_lserr.out | wc -l | sed -e "s/ //g" >> /var/tmp/result_ls

ls -1 -Rr > /var/tmp/ls.out 2>/var/tmp/lserr.out
./ft_ls -Rr > /var/tmp/ft_ls.out 2>/var/tmp/ft_lserr.out
diff /var/tmp/ls.out /var/tmp/ft_ls.out | wc -l | sed -e "s/ //g" >> /var/tmp/result_ls
diff /var/tmp/lserr.out /var/tmp/ft_lserr.out | wc -l | sed -e "s/ //g" >> /var/tmp/result_ls

ls -1 -aRr > /var/tmp/ls.out 2>/var/tmp/lserr.out
./ft_ls -aRr > /var/tmp/ft_ls.out 2>/var/tmp/ft_lserr.out
diff /var/tmp/ls.out /var/tmp/ft_ls.out | wc -l | sed -e "s/ //g" >> /var/tmp/result_ls
diff /var/tmp/lserr.out /var/tmp/ft_lserr.out | wc -l | sed -e "s/ //g" >> /var/tmp/result_ls

ls -1 -tRr > /var/tmp/ls.out 2>/var/tmp/lserr.out
./ft_ls -tRr > /var/tmp/ft_ls.out 2>/var/tmp/ft_lserr.out
diff /var/tmp/ls.out /var/tmp/ft_ls.out | wc -l | sed -e "s/ //g" >> /var/tmp/result_ls
diff /var/tmp/lserr.out /var/tmp/ft_lserr.out | wc -l | sed -e "s/ //g" >> /var/tmp/result_ls

ls -lRr > /var/tmp/ls.out 2>/var/tmp/lserr.out
./ft_ls -lRr > /var/tmp/ft_ls.out 2>/var/tmp/ft_lserr.out
diff /var/tmp/ls.out /var/tmp/ft_ls.out | wc -l | sed -e "s/ //g" >> /var/tmp/result_ls
diff /var/tmp/lserr.out /var/tmp/ft_lserr.out | wc -l | sed -e "s/ //g" >> /var/tmp/result_ls

ls -lRa > /var/tmp/ls.out 2>/var/tmp/lserr.out
./ft_ls -lRa > /var/tmp/ft_ls.out 2>/var/tmp/ft_lserr.out
diff /var/tmp/ls.out /var/tmp/ft_ls.out | wc -l | sed -e "s/ //g" >> /var/tmp/result_ls
diff /var/tmp/lserr.out /var/tmp/ft_lserr.out | wc -l | sed -e "s/ //g" >> /var/tmp/result_ls

ls -1 -tRa > /var/tmp/ls.out 2>/var/tmp/lserr.out
./ft_ls -tRa > /var/tmp/ft_ls.out 2>/var/tmp/ft_lserr.out
diff /var/tmp/ls.out /var/tmp/ft_ls.out | wc -l | sed -e "s/ //g" >> /var/tmp/result_ls
diff /var/tmp/lserr.out /var/tmp/ft_lserr.out | wc -l | sed -e "s/ //g" >> /var/tmp/result_ls

ls -tRl > /var/tmp/ls.out 2>/var/tmp/lserr.out
./ft_ls -tRl > /var/tmp/ft_ls.out 2>/var/tmp/ft_lserr.out
diff /var/tmp/ls.out /var/tmp/ft_ls.out | wc -l | sed -e "s/ //g" >> /var/tmp/result_ls
diff /var/tmp/lserr.out /var/tmp/ft_lserr.out | wc -l | sed -e "s/ //g" >> /var/tmp/result_ls

ls -arl > /var/tmp/ls.out 2>/var/tmp/lserr.out
./ft_ls -arl > /var/tmp/ft_ls.out 2>/var/tmp/ft_lserr.out
diff /var/tmp/ls.out /var/tmp/ft_ls.out | wc -l | sed -e "s/ //g" >> /var/tmp/result_ls
diff /var/tmp/lserr.out /var/tmp/ft_lserr.out | wc -l | sed -e "s/ //g" >> /var/tmp/result_ls

ls -1 -art > /var/tmp/ls.out 2>/var/tmp/lserr.out
./ft_ls -art >/var/tmp/ft_ls.out 2>/var/tmp/ft_lserr.out
diff /var/tmp/ls.out /var/tmp/ft_ls.out | wc -l | sed -e "s/ //g" >> /var/tmp/result_ls
diff /var/tmp/lserr.out /var/tmp/ft_lserr.out | wc -l | sed -e "s/ //g" >> /var/tmp/result_ls

ls -rtl > /var/tmp/ls.out 2>/var/tmp/lserr.out
./ft_ls -rtl > /var/tmp/ft_ls.out 2>/var/tmp/ft_lserr.out
diff /var/tmp/ls.out /var/tmp/ft_ls.out | wc -l | sed -e "s/ //g" >> /var/tmp/result_ls
diff /var/tmp/lserr.out /var/tmp/ft_lserr.out | wc -l | sed -e "s/ //g" >> /var/tmp/result_ls

ls -artl > /var/tmp/ls.out 2>/var/tmp/lserr.out
./ft_ls -artl > /var/tmp/ft_ls.out 2>/var/tmp/ft_lserr.out
diff /var/tmp/ls.out /var/tmp/ft_ls.out | wc -l | sed -e "s/ //g" >> /var/tmp/result_ls
diff /var/tmp/lserr.out /var/tmp/ft_lserr.out | wc -l | sed -e "s/ //g" >> /var/tmp/result_ls

ls -Rrtl > /var/tmp/ls.out 2>/var/tmp/lserr.out
./ft_ls -Rrtl > /var/tmp/ft_ls.out 2>/var/tmp/ft_lserr.out
diff /var/tmp/ls.out /var/tmp/ft_ls.out | wc -l | sed -e "s/ //g" >> /var/tmp/result_ls
diff /var/tmp/lserr.out /var/tmp/ft_lserr.out | wc -l | sed -e "s/ //g" >> /var/tmp/result_ls

ls -Ratl > /var/tmp/ls.out 2>/var/tmp/lserr.out
./ft_ls -Ratl > /var/tmp/ft_ls.out 2>/var/tmp/ft_lserr.out
diff /var/tmp/ls.out /var/tmp/ft_ls.out | wc -l | sed -e "s/ //g" >> /var/tmp/result_ls
diff /var/tmp/lserr.out /var/tmp/ft_lserr.out | wc -l | sed -e "s/ //g" >> /var/tmp/result_ls

ls -Rarl > /var/tmp/ls.out 2>/var/tmp/lserr.out
./ft_ls -Rarl > /var/tmp/ft_ls.out 2>/var/tmp/ft_lserr.out
diff /var/tmp/ls.out /var/tmp/ft_ls.out | wc -l | sed -e "s/ //g" >> /var/tmp/result_ls
diff /var/tmp/lserr.out /var/tmp/ft_lserr.out | wc -l | sed -e "s/ //g" >> /var/tmp/result_ls

ls -1 -Rart > /var/tmp/ls.out 2>/var/tmp/lserr.out
./ft_ls -Rart > /var/tmp/ft_ls.out 2>/var/tmp/ft_lserr.out
diff /var/tmp/ls.out /var/tmp/ft_ls.out | wc -l | sed -e "s/ //g" >> /var/tmp/result_ls
diff /var/tmp/lserr.out /var/tmp/ft_lserr.out | wc -l | sed -e "s/ //g" >> /var/tmp/result_ls

ls -Rarlt > /var/tmp/ls.out 2>/var/tmp/lserr.out
./ft_ls -Rarlt > /var/tmp/ft_ls.out 2>/var/tmp/ft_lserr.out
diff /var/tmp/ls.out /var/tmp/ft_ls.out | wc -l | sed -e "s/ //g" >> /var/tmp/result_ls
diff /var/tmp/lserr.out /var/tmp/ft_lserr.out | wc -l | sed -e "s/ //g" >> /var/tmp/result_ls



echo "Test 1 flag : "
echo "-> OK  \c"
cat /var/tmp/result_ls | grep "0" | wc -l | sed -e "s/ //g"
echo "-> NOK \c"
cat /var/tmp/result_ls | grep -v "0" | wc -l | sed -e "s/ //g"



#test flags separes
ls -l -a > /var/tmp/ls.out 2>/var/tmp/lserr.out
./ft_ls -l -a > /var/tmp/ft_ls.out 2>/var/tmp/ft_lserr.out
diff /var/tmp/ls.out /var/tmp/ft_ls.out | wc -l | sed -e "s/ //g" > /var/tmp/result_ls
diff /var/tmp/lserr.out /var/tmp/ft_lserr.out | wc -l | sed -e "s/ //g" >> /var/tmp/result_ls

ls -1 -a -r > /var/tmp/ls.out 2>/var/tmp/lserr.out
./ft_ls -a -r > /var/tmp/ft_ls.out 2>/var/tmp/ft_lserr.out
diff /var/tmp/ls.out /var/tmp/ft_ls.out | wc -l | sed -e "s/ //g" >> /var/tmp/result_ls
diff /var/tmp/lserr.out /var/tmp/ft_lserr.out | wc -l | sed -e "s/ //g" >> /var/tmp/result_ls


ls -1 -a -t > /var/tmp/ls.out 2>/var/tmp/lserr.out
./ft_ls -a -t > /var/tmp/ft_ls.out 2>/var/tmp/ft_lserr.out
diff /var/tmp/ls.out /var/tmp/ft_ls.out | wc -l | sed -e "s/ //g" >> /var/tmp/result_ls
diff /var/tmp/lserr.out /var/tmp/ft_lserr.out | wc -l | sed -e "s/ //g" >> /var/tmp/result_ls


ls -1 -r -t > /var/tmp/ls.out 2>/var/tmp/lserr.out
./ft_ls -r -t > /var/tmp/ft_ls.out 2>/var/tmp/ft_lserr.out
diff /var/tmp/ls.out /var/tmp/ft_ls.out | wc -l | sed -e "s/ //g" >> /var/tmp/result_ls
diff /var/tmp/lserr.out /var/tmp/ft_lserr.out | wc -l | sed -e "s/ //g" >> /var/tmp/result_ls

ls -r -l > /var/tmp/ls.out 2>/var/tmp/lserr.out
./ft_ls -r -l > /var/tmp/ft_ls.out 2>/var/tmp/ft_lserr.out
diff /var/tmp/ls.out /var/tmp/ft_ls.out | wc -l | sed -e "s/ //g" >> /var/tmp/result_ls
diff /var/tmp/lserr.out /var/tmp/ft_lserr.out | wc -l | sed -e "s/ //g" >> /var/tmp/result_ls

ls -t -l > /var/tmp/ls.out 2>/var/tmp/lserr.out
./ft_ls -t -l > /var/tmp/ft_ls.out 2>/var/tmp/ft_lserr.out
diff /var/tmp/ls.out /var/tmp/ft_ls.out | wc -l | sed -e "s/ //g" >> /var/tmp/result_ls
diff /var/tmp/lserr.out /var/tmp/ft_lserr.out | wc -l | sed -e "s/ //g" >> /var/tmp/result_ls

ls -a -r -l > /var/tmp/ls.out 2>/var/tmp/lserr.out
./ft_ls -a -r -l > /var/tmp/ft_ls.out 2>/var/tmp/ft_lserr.out
diff /var/tmp/ls.out /var/tmp/ft_ls.out | wc -l | sed -e "s/ //g" >> /var/tmp/result_ls
diff /var/tmp/lserr.out /var/tmp/ft_lserr.out | wc -l | sed -e "s/ //g" >> /var/tmp/result_ls

ls -1 -a -r -t > /var/tmp/ls.out 2>/var/tmp/lserr.out
./ft_ls -a -r -t > /var/tmp/ft_ls.out 2>/var/tmp/ft_lserr.out
diff /var/tmp/ls.out /var/tmp/ft_ls.out | wc -l | sed -e "s/ //g" >> /var/tmp/result_ls
diff /var/tmp/lserr.out /var/tmp/ft_lserr.out | wc -l | sed -e "s/ //g" >> /var/tmp/result_ls

ls -r -t -l > /var/tmp/ls.out 2>/var/tmp/lserr.out
./ft_ls -r -t -l > /var/tmp/ft_ls.out 2>/var/tmp/ft_lserr.out
diff /var/tmp/ls.out /var/tmp/ft_ls.out | wc -l | sed -e "s/ //g" >> /var/tmp/result_ls
diff /var/tmp/lserr.out /var/tmp/ft_lserr.out | wc -l | sed -e "s/ //g" >> /var/tmp/result_ls

ls -a -r -t -l > /var/tmp/ls.out 2>/var/tmp/lserr.out
./ft_ls -a -r -t -l > /var/tmp/ft_ls.out 2>/var/tmp/ft_lserr.out
diff /var/tmp/ls.out /var/tmp/ft_ls.out | wc -l | sed -e "s/ //g" >> /var/tmp/result_ls
diff /var/tmp/lserr.out /var/tmp/ft_lserr.out | wc -l | sed -e "s/ //g" >> /var/tmp/result_ls

#################
ls -l -a > /var/tmp/ls.out 2>/var/tmp/lserr.out
./ft_ls -l -a > /var/tmp/ft_ls.out 2>/var/tmp/ft_lserr.out
diff /var/tmp/ls.out /var/tmp/ft_ls.out | wc -l | sed -e "s/ //g" >> /var/tmp/result_ls
diff /var/tmp/lserr.out /var/tmp/ft_lserr.out | wc -l | sed -e "s/ //g" >> /var/tmp/result_ls

ls -1 -a -r > /var/tmp/ls.out 2>/var/tmp/lserr.out
./ft_ls -a -r > /var/tmp/ft_ls.out 2>/var/tmp/ft_lserr.out
diff /var/tmp/ls.out /var/tmp/ft_ls.out | wc -l | sed -e "s/ //g" >> /var/tmp/result_ls
diff /var/tmp/lserr.out /var/tmp/ft_lserr.out | wc -l | sed -e "s/ //g" >> /var/tmp/result_ls


ls -1 -a -t > /var/tmp/ls.out 2>/var/tmp/lserr.out
./ft_ls -a -t > /var/tmp/ft_ls.out 2>/var/tmp/ft_lserr.out
diff /var/tmp/ls.out /var/tmp/ft_ls.out | wc -l | sed -e "s/ //g" >> /var/tmp/result_ls
diff /var/tmp/lserr.out /var/tmp/ft_lserr.out | wc -l | sed -e "s/ //g" >> /var/tmp/result_ls

ls -1 -a -R > /var/tmp/ls.out 2>/var/tmp/lserr.out
./ft_ls -a -R > /var/tmp/ft_ls.out 2>/var/tmp/ft_lserr.out
diff /var/tmp/ls.out /var/tmp/ft_ls.out | wc -l | sed -e "s/ //g" >> /var/tmp/result_ls
diff /var/tmp/lserr.out /var/tmp/ft_lserr.out | wc -l | sed -e "s/ //g" >> /var/tmp/result_ls

ls -1 -r -t > /var/tmp/ls.out 2>/var/tmp/lserr.out
./ft_ls -r -t > /var/tmp/ft_ls.out 2>/var/tmp/ft_lserr.out
diff /var/tmp/ls.out /var/tmp/ft_ls.out | wc -l | sed -e "s/ //g" >> /var/tmp/result_ls
diff /var/tmp/lserr.out /var/tmp/ft_lserr.out | wc -l | sed -e "s/ //g" >> /var/tmp/result_ls

ls -r -l > /var/tmp/ls.out 2>/var/tmp/lserr.out
./ft_ls -r -l > /var/tmp/ft_ls.out 2>/var/tmp/ft_lserr.out
diff /var/tmp/ls.out /var/tmp/ft_ls.out | wc -l | sed -e "s/ //g" >> /var/tmp/result_ls
diff /var/tmp/lserr.out /var/tmp/ft_lserr.out | wc -l | sed -e "s/ //g" >> /var/tmp/result_ls

ls -r -R > /var/tmp/ls.out 2>/var/tmp/lserr.out
./ft_ls -r -R > /var/tmp/ft_ls.out 2>/var/tmp/ft_lserr.out
diff /var/tmp/ls.out /var/tmp/ft_ls.out | wc -l | sed -e "s/ //g" >> /var/tmp/result_ls
diff /var/tmp/lserr.out /var/tmp/ft_lserr.out | wc -l | sed -e "s/ //g" >> /var/tmp/result_ls


ls -t -l > /var/tmp/ls.out 2>/var/tmp/lserr.out
./ft_ls -t -l > /var/tmp/ft_ls.out 2>/var/tmp/ft_lserr.out
diff /var/tmp/ls.out /var/tmp/ft_ls.out | wc -l | sed -e "s/ //g" >> /var/tmp/result_ls
diff /var/tmp/lserr.out /var/tmp/ft_lserr.out | wc -l | sed -e "s/ //g" >> /var/tmp/result_ls

ls -1 -t -R > /var/tmp/ls.out 2>/var/tmp/lserr.out
./ft_ls -t -R > /var/tmp/ft_ls.out 2>/var/tmp/ft_lserr.out
diff /var/tmp/ls.out /var/tmp/ft_ls.out | wc -l | sed -e "s/ //g" >> /var/tmp/result_ls
diff /var/tmp/lserr.out /var/tmp/ft_lserr.out | wc -l | sed -e "s/ //g" >> /var/tmp/result_ls

ls -l -R > /var/tmp/ls.out 2>/var/tmp/lserr.out
./ft_ls -l -R > /var/tmp/ft_ls.out 2>/var/tmp/ft_lserr.out
diff /var/tmp/ls.out /var/tmp/ft_ls.out | wc -l | sed -e "s/ //g" >> /var/tmp/result_ls
diff /var/tmp/lserr.out /var/tmp/ft_lserr.out | wc -l | sed -e "s/ //g" >> /var/tmp/result_ls


ls -a -r -l > /var/tmp/ls.out 2>/var/tmp/lserr.out
./ft_ls -a -r -l > /var/tmp/ft_ls.out 2>/var/tmp/ft_lserr.out
diff /var/tmp/ls.out /var/tmp/ft_ls.out | wc -l | sed -e "s/ //g" >> /var/tmp/result_ls
diff /var/tmp/lserr.out /var/tmp/ft_lserr.out | wc -l | sed -e "s/ //g" >> /var/tmp/result_ls

ls -R -r -l > /var/tmp/ls.out 2>/var/tmp/lserr.out
./ft_ls -R -r -l > /var/tmp/ft_ls.out 2>/var/tmp/ft_lserr.out
diff /var/tmp/ls.out /var/tmp/ft_ls.out | wc -l | sed -e "s/ //g" >> /var/tmp/result_ls
diff /var/tmp/lserr.out /var/tmp/ft_lserr.out | wc -l | sed -e "s/ //g" >> /var/tmp/result_ls

ls -R -a -l > /var/tmp/ls.out 2>/var/tmp/lserr.out
./ft_ls -R -a -l > /var/tmp/ft_ls.out 2>/var/tmp/ft_lserr.out
diff /var/tmp/ls.out /var/tmp/ft_ls.out | wc -l | sed -e "s/ //g" >> /var/tmp/result_ls
diff /var/tmp/lserr.out /var/tmp/ft_lserr.out | wc -l | sed -e "s/ //g" >> /var/tmp/result_ls

ls -R -r -a > /var/tmp/ls.out 2>/var/tmp/lserr.out
./ft_ls -R -r -a > /var/tmp/ft_ls.out 2>/var/tmp/ft_lserr.out
diff /var/tmp/ls.out /var/tmp/ft_ls.out | wc -l | sed -e "s/ //g" >> /var/tmp/result_ls
diff /var/tmp/lserr.out /var/tmp/ft_lserr.out | wc -l | sed -e "s/ //g" >> /var/tmp/result_ls

ls -1 -a -r -t > /var/tmp/ls.out 2>/var/tmp/lserr.out
./ft_ls -a -r -t > /var/tmp/ft_ls.out 2>/var/tmp/ft_lserr.out
diff /var/tmp/ls.out /var/tmp/ft_ls.out | wc -l | sed -e "s/ //g" >> /var/tmp/result_ls
diff /var/tmp/lserr.out /var/tmp/ft_lserr.out | wc -l | sed -e "s/ //g" >> /var/tmp/result_ls

ls -r -t -l > /var/tmp/ls.out 2>/var/tmp/lserr.out
./ft_ls -r -t -l > /var/tmp/ft_ls.out 2>/var/tmp/ft_lserr.out
diff /var/tmp/ls.out /var/tmp/ft_ls.out | wc -l | sed -e "s/ //g" >> /var/tmp/result_ls
diff /var/tmp/lserr.out /var/tmp/ft_lserr.out | wc -l | sed -e "s/ //g" >> /var/tmp/result_ls

ls -a -r -t -l > /var/tmp/ls.out 2>/var/tmp/lserr.out
./ft_ls -a -r -t -l > /var/tmp/ft_ls.out 2>/var/tmp/ft_lserr.out
diff /var/tmp/ls.out /var/tmp/ft_ls.out | wc -l | sed -e "s/ //g" >> /var/tmp/result_ls
diff /var/tmp/lserr.out /var/tmp/ft_lserr.out | wc -l | sed -e "s/ //g" >> /var/tmp/result_ls

ls -a -r -t -l -R > /var/tmp/ls.out 2>/var/tmp/lserr.out
./ft_ls -a -r -t -l -R > /var/tmp/ft_ls.out 2>/var/tmp/ft_lserr.out
diff /var/tmp/ls.out /var/tmp/ft_ls.out | wc -l | sed -e "s/ //g" >> /var/tmp/result_ls
diff /var/tmp/lserr.out /var/tmp/ft_lserr.out | wc -l | sed -e "s/ //g" >> /var/tmp/result_ls

echo "Test 2 flag : "
echo "-> OK  \c"
cat /var/tmp/result_ls | grep "0" | wc -l | sed -e "s/ //g"
echo "-> NOK \c"
cat /var/tmp/result_ls | grep -v "0" | wc -l | sed -e "s/ //g"


###### TEST INVALID FLAGS ########
ls --a  2>&1| sed -e "s/\[[-A-Za-z0-9]*]//g" | sed -e "s/ls/ft_ls/g" > /var/tmp/ls.out
./ft_ls --a 2>&1 | sed -e "s/\[[-A-Za-z0-9]*]//g"  > /var/tmp/ft_ls.out
diff /var/tmp/ls.out /var/tmp/ft_ls.out | wc -l | sed -e "s/ //g" > /var/tmp/result_ls

ls -a-  2>&1| sed -e "s/\[[-A-Za-z0-9]*]//g"| sed -e "s/ls/ft_ls/g" > /var/tmp/ls.out
./ft_ls -a- 2>&1 | sed -e "s/\[[-A-Za-z0-9]*]//g"  > /var/tmp/ft_ls.out
diff /var/tmp/ls.out /var/tmp/ft_ls.out | wc -l | sed -e "s/ //g" >> /var/tmp/result_ls

ls -Z  2>&1| sed -e "s/\[[-A-Za-z0-9]*]//g" | sed -e "s/ls/ft_ls/g" > /var/tmp/ls.out
./ft_ls -Z 2>&1 | sed -e "s/\[[-A-Za-z0-9]*]//g"  > /var/tmp/ft_ls.out
diff /var/tmp/ls.out /var/tmp/ft_ls.out | wc -l | sed -e "s/ //g" >> /var/tmp/result_ls

ls -a -r -Z  2>&1| sed -e "s/\[[-A-Za-z0-9]*]//g"| sed -e "s/ls/ft_ls/g" > /var/tmp/ls.out
./ft_ls -a -r -Z 2>&1 | sed -e "s/\[[-A-Za-z0-9]*]//g"  > /var/tmp/ft_ls.out
diff /var/tmp/ls.out /var/tmp/ft_ls.out | wc -l | sed -e "s/ //g" >> /var/tmp/result_ls

ls -arZ  2>&1| sed -e "s/\[[-A-Za-z0-9]*]//g" | sed -e "s/ls/ft_ls/g" > /var/tmp/ls.out
./ft_ls -arZ 2>&1 | sed -e "s/\[[-A-Za-z0-9]*]//g"  > /var/tmp/ft_ls.out
diff /var/tmp/ls.out /var/tmp/ft_ls.out | wc -l | sed -e "s/ //g" >> /var/tmp/result_ls

ls -arZt  2>&1| sed -e "s/\[[-A-Za-z0-9]*]//g" | sed -e "s/ls/ft_ls/g" > /var/tmp/ls.out
./ft_ls -arZt 2>&1 | sed -e "s/\[[-A-Za-z0-9]*]//g"  > /var/tmp/ft_ls.out
diff /var/tmp/ls.out /var/tmp/ft_ls.out | wc -l | sed -e "s/ //g" >> /var/tmp/result_ls

echo "Test invalid flags : "
echo "-> OK  \c"
cat /var/tmp/result_ls | grep "0" | wc -l | sed -e "s/ //g"
echo "-> NOK \c"
cat /var/tmp/result_ls | grep -v "0" | wc -l | sed -e "s/ //g"

###### test invalid files #######
ls dsf dgfg gthy hhy aaa sf vdf bdfgdf 2>&1 | sed -e "s/ls/ft_ls/g" > /var/tmp/ls.out
./ft_ls dsf dgfg gthy hhy aaa sf vdf bdfgdf 2> /var/tmp/ft_ls.out 
diff /var/tmp/ls.out /var/tmp/ft_ls.out | wc -l | sed -e "s/ //g" > /var/tmp/result_ls

ls sd 2>&1 | sed -e "s/ls/ft_ls/g" > /var/tmp/ls.out
./ft_ls sd 2> /var/tmp/ft_ls.out 
diff /var/tmp/ls.out /var/tmp/ft_ls.out | wc -l | sed -e "s/ //g" >> /var/tmp/result_ls


echo "Test invalid files : "
echo "-> OK  \c"
cat /var/tmp/result_ls | grep "0" | wc -l | sed -e "s/ //g"
echo "-> NOK \c"
cat /var/tmp/result_ls | grep -v "0" | wc -l | sed -e "s/ //g"

###### multi tests #####
ls -1 -art A . . A . sf  2>/dev/null > /var/tmp/ls.out
ls -1 -art A . . A . sf  2>&1 >/dev/null | sed -e "s/ls/ft_ls/g" > /var/tmp/lserr.out
./ft_ls -art A . . A . sf  > /var/tmp/ft_ls.out 2>/var/tmp/ft_lserr.out
diff /var/tmp/ls.out /var/tmp/ft_ls.out | wc -l | sed -e "s/ //g" > /var/tmp/result_ls
diff /var/tmp/lserr.out /var/tmp/ft_lserr.out | wc -l | sed -e "s/ //g" >> /var/tmp/result_ls

ls -alrt A . . A . sf  2>/dev/null > /var/tmp/ls.out
ls -alrt A . . A . sf  2>&1 >/dev/null | sed -e "s/ls/ft_ls/g" > /var/tmp/lserr.out
./ft_ls -alrt A . . A . sf   > /var/tmp/ft_ls.out 2>/var/tmp/ft_lserr.out
diff /var/tmp/ls.out /var/tmp/ft_ls.out | wc -l | sed -e "s/ //g" >> /var/tmp/result_ls
diff /var/tmp/lserr.out /var/tmp/ft_lserr.out | wc -l | sed -e "s/ //g" >> /var/tmp/result_ls

ls  -alRrt A . . A . sf  2>/dev/null > /var/tmp/ls.out
ls  -alRrt A . . A . sf   2>&1 >/dev/null | sed -e "s/ls/ft_ls/g" > /var/tmp/lserr.out
./ft_ls -alRrt A . . A . sf   > /var/tmp/ft_ls.out 2>/var/tmp/ft_lserr.out
diff /var/tmp/ls.out /var/tmp/ft_ls.out | wc -l | sed -e "s/ //g" >> /var/tmp/result_ls
diff /var/tmp/lserr.out /var/tmp/ft_lserr.out | wc -l | sed -e "s/ //g" >> /var/tmp/result_ls

ls  -alRt A . . A . sf  2>/dev/null > /var/tmp/ls.out
ls  -alRt A . . A . sf  2>&1 >/dev/null | sed -e "s/ls/ft_ls/g" > /var/tmp/lserr.out
./ft_ls -alRt A . . A . sf   > /var/tmp/ft_ls.out 2>/var/tmp/ft_lserr.out
diff /var/tmp/ls.out /var/tmp/ft_ls.out | wc -l | sed -e "s/ //g" >> /var/tmp/result_ls
diff /var/tmp/lserr.out /var/tmp/ft_lserr.out | wc -l | sed -e "s/ //g" >> /var/tmp/result_ls

ls  -alrR A . . A . sf  2>/dev/null > /var/tmp/ls.out
ls  -alrR A . . A . sf   2>&1 >/dev/null | sed -e "s/ls/ft_ls/g" > /var/tmp/lserr.out
./ft_ls -alrR A . . A . sf   > /var/tmp/ft_ls.out 2>/var/tmp/ft_lserr.out
diff /var/tmp/ls.out /var/tmp/ft_ls.out | wc -l | sed -e "s/ //g" >> /var/tmp/result_ls
diff /var/tmp/lserr.out /var/tmp/ft_lserr.out | wc -l | sed -e "s/ //g" >> /var/tmp/result_ls

ls  -alrR A . . A . sf  2>/dev/null > /var/tmp/ls.out
ls  -alrR A . . A . sf   2>&1 >/dev/null | sed -e "s/ls/ft_ls/g" > /var/tmp/lserr.out
./ft_ls -alrR A . . A . sf   > /var/tmp/ft_ls.out 2>/var/tmp/ft_lserr.out
diff /var/tmp/ls.out /var/tmp/ft_ls.out | wc -l | sed -e "s/ //g" >> /var/tmp/result_ls
diff /var/tmp/lserr.out /var/tmp/ft_lserr.out | wc -l | sed -e "s/ //g" >> /var/tmp/result_ls

ls -alrRt A/nnas ft_ls A/lnk test.sh A/.CD A A/FFD 2>/dev/null > /var/tmp/ls.out
ls -alrRt A/nnas ft_ls A/lnk test.sh A/.CD A A/FFD   2>&1 >/dev/null | sed -e "s/ls/ft_ls/g" > /var/tmp/lserr.out
./ft_ls -alrRt  A/nnas ft_ls A/lnk test.sh A/.CD A A/FFD    > /var/tmp/ft_ls.out 2>/var/tmp/ft_lserr.out
diff /var/tmp/ls.out /var/tmp/ft_ls.out | wc -l | sed -e "s/ //g" >> /var/tmp/result_ls
diff /var/tmp/lserr.out /var/tmp/ft_lserr.out | wc -l | sed -e "s/ //g" >> /var/tmp/result_ls

ls -alrRt A/nnas ft_ls A/lnk test.sh A/.CD -l A A/FFD 2>/dev/null > /var/tmp/ls.out
ls -alrRt A/nnas ft_ls A/lnk test.sh A/.CD -l A A/FFD   2>&1 >/dev/null | sed -e "s/ls/ft_ls/g" > /var/tmp/lserr.out
./ft_ls -alrRt  A/nnas ft_ls A/lnk test.sh -l A/.CD A A/FFD    > /var/tmp/ft_ls.out 2>/var/tmp/ft_lserr.out
diff /var/tmp/ls.out /var/tmp/ft_ls.out | wc -l | sed -e "s/ //g" >> /var/tmp/result_ls
diff /var/tmp/lserr.out /var/tmp/ft_lserr.out | wc -l | sed -e "s/ //g" >> /var/tmp/result_ls

ls -lrRt A/nnas ft_ls A/lnk test.sh A/.CD -l A A/FFD - 2>/dev/null > /var/tmp/ls.out
ls -lrRt A/nnas ft_ls A/lnk test.sh A/.CD -l A A/FFD -   2>&1 >/dev/null | sed -e "s/ls/ft_ls/g" > /var/tmp/lserr.out
./ft_ls -lrRt  A/nnas ft_ls A/lnk test.sh -l A/.CD A A/FFD -   > /var/tmp/ft_ls.out 2>/var/tmp/ft_lserr.out
diff /var/tmp/ls.out /var/tmp/ft_ls.out | wc -l | sed -e "s/ //g" >> /var/tmp/result_ls
diff /var/tmp/lserr.out /var/tmp/ft_lserr.out | wc -l | sed -e "s/ //g" >> /var/tmp/result_ls

ls -alrR A/nnas ft_ls A/lnk test.sh A/.CD -l A A/FFD - 2>/dev/null > /var/tmp/ls.out
ls -alrR A/nnas ft_ls A/lnk test.sh A/.CD -l A A/FFD -   2>&1 >/dev/null | sed -e "s/ls/ft_ls/g" > /var/tmp/lserr.out
./ft_ls -alrR  A/nnas ft_ls A/lnk test.sh -l A/.CD A A/FFD -   > /var/tmp/ft_ls.out 2>/var/tmp/ft_lserr.out
diff /var/tmp/ls.out /var/tmp/ft_ls.out | wc -l | sed -e "s/ //g" >> /var/tmp/result_ls
diff /var/tmp/lserr.out /var/tmp/ft_lserr.out | wc -l | sed -e "s/ //g" >> /var/tmp/result_ls

ls -lrRt A/.CD 2>/dev/null > /var/tmp/ls.out
ls -lrRt A/.CD   2>&1 >/dev/null | sed -e "s/ls/ft_ls/g" > /var/tmp/lserr.out
./ft_ls -lrRt A/.CD   > /var/tmp/ft_ls.out 2>/var/tmp/ft_lserr.out
diff /var/tmp/ls.out /var/tmp/ft_ls.out | wc -l | sed -e "s/ //g" >> /var/tmp/result_ls
diff /var/tmp/lserr.out /var/tmp/ft_lserr.out | wc -l | sed -e "s/ //g" >> /var/tmp/result_ls


echo "Tests multi : "
echo "-> OK  \c"
cat /var/tmp/result_ls | grep "0" | wc -l | sed -e "s/ //g"
echo "-> NOK \c"
cat /var/tmp/result_ls | grep -v "0" | wc -l | sed -e "s/ //g"


###### remove rights #####

chmod 222 A/YYT
chmod 222 A/.GGF
chmod 222 A/.CD/lnk
ls  -arlt A 2>/dev/null > /var/tmp/ls.out
ls  -arlt A  2>&1 >/dev/null | sed -e "s/ls/ft_ls/g" > /var/tmp/lserr.out
./ft_ls -arlt A  > /var/tmp/ft_ls.out 2>/var/tmp/ft_lserr.out
diff /var/tmp/ls.out /var/tmp/ft_ls.out  | wc -l | sed -e "s/ //g"  > /var/tmp/result_ls
diff /var/tmp/lserr.out /var/tmp/ft_lserr.out | wc -l | sed -e "s/ //g" >> /var/tmp/result_ls

ls -alrt A . . A . sf  2>/dev/null > /var/tmp/ls.out
ls -alrt A . . A . sf 2>&1 >/dev/null | sed -e "s/ls/ft_ls/g" > /var/tmp/lserr.out
./ft_ls -alrt A . . A . sf  > /var/tmp/ft_ls.out 2>/var/tmp/ft_lserr.out
diff /var/tmp/ls.out /var/tmp/ft_ls.out | wc -l | sed -e "s/ //g" >> /var/tmp/result_ls
diff /var/tmp/lserr.out /var/tmp/ft_lserr.out | wc -l | sed -e "s/ //g" >> /var/tmp/result_ls

ls -alRrt . sf  2>/dev/null > /var/tmp/ls.out
ls -alRrt . sf  2>&1 >/dev/null | sed -e "s/ls/ft_ls/g" > /var/tmp/lserr.out
./ft_ls -alRrt . sf  > /var/tmp/ft_ls.out 2>/var/tmp/ft_lserr.out
diff /var/tmp/ls.out /var/tmp/ft_ls.out | wc -l | sed -e "s/ //g" >> /var/tmp/result_ls
diff /var/tmp/lserr.out /var/tmp/ft_lserr.out | wc -l | sed -e "s/ //g" >> /var/tmp/result_ls

ls -alRt A . . A . sf  2>/dev/null > /var/tmp/ls.out
ls -alRt A . . A . sf 2>&1 >/dev/null | sed -e "s/ls/ft_ls/g" > /var/tmp/lserr.out
./ft_ls -alRt A . . A . sf  > /var/tmp/ft_ls.out 2>/var/tmp/ft_lserr.out
diff /var/tmp/ls.out /var/tmp/ft_ls.out | wc -l | sed -e "s/ //g" >> /var/tmp/result_ls
diff /var/tmp/lserr.out /var/tmp/ft_lserr.out | wc -l | sed -e "s/ //g" >> /var/tmp/result_ls

ls -alrR A . . A . sf 2>/dev/null > /var/tmp/ls.out
ls -alrR A . . A . sf 2>&1 >/dev/null | sed -e "s/ls/ft_ls/g" > /var/tmp/lserr.out
./ft_ls -alrR A . . A . sf  > /var/tmp/ft_ls.out 2>/var/tmp/ft_lserr.out
diff /var/tmp/ls.out /var/tmp/ft_ls.out | wc -l | sed -e "s/ //g" >> /var/tmp/result_ls
diff /var/tmp/lserr.out /var/tmp/ft_lserr.out | wc -l | sed -e "s/ //g" >> /var/tmp/result_ls

ls -alrR A . . A . sf 2>/dev/null > /var/tmp/ls.out
ls -alrR A . . A . sf 2>&1 >/dev/null | sed -e "s/ls/ft_ls/g" > /var/tmp/lserr.out
./ft_ls -alrR A . . A . sf > /var/tmp/ft_ls.out 2>/var/tmp/ft_lserr.out
diff /var/tmp/ls.out /var/tmp/ft_ls.out | wc -l | sed -e "s/ //g" >> /var/tmp/result_ls
diff /var/tmp/lserr.out /var/tmp/ft_lserr.out | wc -l | sed -e "s/ //g" >> /var/tmp/result_ls

ls -alrRt A/nnas ft_ls A/lnk test.sh A/.CD A A/FFD 2>/dev/null > /var/tmp/ls.out
ls -alrRt A/nnas ft_ls A/lnk test.sh A/.CD A A/FFD 2>&1 >/dev/null | sed -e "s/ls/ft_ls/g" > /var/tmp/lserr.out
./ft_ls -alrRt  A/nnas ft_ls A/lnk test.sh A/.CD A A/FFD  > /var/tmp/ft_ls.out 2>/var/tmp/ft_lserr.out
diff /var/tmp/ls.out /var/tmp/ft_ls.out | wc -l | sed -e "s/ //g" >> /var/tmp/result_ls
diff /var/tmp/lserr.out /var/tmp/ft_lserr.out | wc -l | sed -e "s/ //g" >> /var/tmp/result_ls

ls -alrRt A/nnas ft_ls A/lnk test.sh A/.CD -l A A/FFD 2>/dev/null > /var/tmp/ls.out
ls -alrRt A/nnas ft_ls A/lnk test.sh A/.CD -l A A/FFD 2>&1 >/dev/null | sed -e "s/ls/ft_ls/g" > /var/tmp/lserr.out
./ft_ls -alrRt  A/nnas ft_ls A/lnk test.sh A/.CD -l A A/FFD > /var/tmp/ft_ls.out 2>/var/tmp/ft_lserr.out
diff /var/tmp/ls.out /var/tmp/ft_ls.out | wc -l | sed -e "s/ //g" >> /var/tmp/result_ls
diff /var/tmp/lserr.out /var/tmp/ft_lserr.out | wc -l | sed -e "s/ //g" >> /var/tmp/result_ls

ls -lrRt A/nnas ft_ls A/lnk test.sh A/.CD -l A A/FFD - 2>/dev/null > /var/tmp/ls.out
ls -lrRt A/nnas ft_ls A/lnk test.sh A/.CD -l A A/FFD - 2>&1 >/dev/null | sed -e "s/ls/ft_ls/g" > /var/tmp/lserr.out
./ft_ls -lrRt  A/nnas ft_ls A/lnk test.sh A/.CD -l A A/FFD - > /var/tmp/ft_ls.out 2>/var/tmp/ft_lserr.out
diff /var/tmp/ls.out /var/tmp/ft_ls.out | wc -l | sed -e "s/ //g" >> /var/tmp/result_ls
diff /var/tmp/lserr.out /var/tmp/ft_lserr.out | wc -l | sed -e "s/ //g" >> /var/tmp/result_ls

ls -alrR A/nnas ft_ls A/YYT A/lnk test.sh A/.GGF A/.CD -l A A/FFD - 2>/dev/null > /var/tmp/ls.out
ls -alrR A/nnas ft_ls A/YYT A/lnk test.sh A/.GGF A/.CD -l A A/FFD - 2>&1 >/dev/null | sed -e "s/ls/ft_ls/g" > /var/tmp/lserr.out
./ft_ls -alrR  A/nnas A/YYT ft_ls A/lnk test.sh A/.GGF A/.CD -l A A/FFD - > /var/tmp/ft_ls.out 2>/var/tmp/ft_lserr.out
diff /var/tmp/ls.out /var/tmp/ft_ls.out | wc -l | sed -e "s/ //g" >> /var/tmp/result_ls
diff /var/tmp/lserr.out /var/tmp/ft_lserr.out | wc -l | sed -e "s/ //g" >> /var/tmp/result_ls

ls -lrRt A/.CD 2>/dev/null > /var/tmp/ls.out
ls -lrRt A/.CD 2>&1 >/dev/null | sed -e "s/ls/ft_ls/g" > /var/tmp/lserr.out
./ft_ls -lrRt A/.CD > /var/tmp/ft_ls.out 2>/var/tmp/ft_lserr.out
diff /var/tmp/ls.out /var/tmp/ft_ls.out | wc -l | sed -e "s/ //g" >> /var/tmp/result_ls
diff /var/tmp/lserr.out /var/tmp/ft_lserr.out | wc -l | sed -e "s/ //g" >> /var/tmp/result_ls

echo "Tests access denied : "
echo "-> OK  \c"
cat /var/tmp/result_ls | grep "0" | wc -l | sed -e "s/ //g"
echo "-> NOK \c"
cat /var/tmp/result_ls | grep -v "0" | wc -l | sed -e "s/ //g"
chmod -R 777 *

