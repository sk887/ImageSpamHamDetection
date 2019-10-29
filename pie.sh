tesseract "$1" out
printf "\n\n"
echo "..........Tesseract extracting image text.........."
cat out.txt
printf "\n\n"
./converter <out.txt > a1
echo "..........The output of image after converting into small letters.........."
printf "\n\n"
cat a1
./stemmer <a1 > b1
printf "\n\n"
echo "..........The output of the image after converting into root words.........."
cat b1
./classifier <b1
printf "\n\n"
printf "\n\n"

