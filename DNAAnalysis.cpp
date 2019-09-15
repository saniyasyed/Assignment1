#include <iostream>
#include <fstream>
#include <math.h>
#include <cstdlib>
#include <time.h>
#define _USE_MATH_DEFINES
using namespace std;

// delcaring all variables globally
string line = "";
int countA = 0;
int countC = 0;
int countT = 0;
int countG = 0;
float DNAsum = 0;
int aa = 0, cc = 0, tt = 0, gg = 0;
int ac = 0, at = 0, ag = 0;
int ca = 0, ct = 0, cg = 0;
int ta = 0, tc = 0, tg = 0;
int ga = 0, gc = 0, gt = 0;
float countBigram = 0;
char dna, dna1;
float lineCount = 0;
float meanNum = 0;
float variance = 0;
float stDev = 0;
float a,b,c,d;
int aNeed,cNeed,tNeed,gNeed;
bool user = true;
char userChoice;
ifstream inputStreamer;
ofstream outputStreamer;




// Method to calculate mean and outputs the result to the file
int calcMean()
{

  meanNum = DNAsum / lineCount;
  outputStreamer << "MEAN:" << meanNum << endl;

}
// Method to calculate variance and standard deviation and outputs result to the file
int calcVarStdev(string fileName)
{
  //creating a new input stream object to read file for calculating variation and standard deviation
  ifstream inputFileStream;
  inputFileStream.open(fileName);
  inputStreamer.open(fileName);
  float varTemp;
  float tempNum;

  //iterating through file
  while(getline(inputFileStream, line))
  {
    varTemp += pow((int)line.length() - meanNum, 2);
  }

  variance = (varTemp)/ (lineCount - 1);
  outputStreamer << "VARIANCE: " << variance << endl;

  // calculates standard deviation using the variance
  stDev = sqrt(variance);
  outputStreamer << "STANDARD DEVIATION: " << stDev << endl;
  inputFileStream.close();
}

// Method to calculate the Gaussian value and returns it
float calcGaussian()
{
  // normalizing the random numbers
  float a = (float) rand() / (float)RAND_MAX;
  float b = (float) rand() / (float)RAND_MAX;
  float c = sqrt(-2 * log(a)) * cos(2* M_PI * b);
  float d = sqrt(variance) * c + meanNum;
  //returning the gaussian value
  return d;

}

// main method
int main(int argc, char** argv)
{
  // making sure all randomly generated numbers are different
  srand(time(NULL));
  string fileName;
  // setting fileName to a command line argument
  fileName = argv[1];
  // opening fileName in the inputStreamer and SaniyaSyed.out in the outputStreamer
  inputStreamer.open(fileName);
  outputStreamer.open("SaniyaSyed.out");
  // testing to see if user inputted a file correctly
  if(!inputStreamer)
  {
    cerr << "Unable to open " << fileName << endl;
    //exits out of the program if not a valid file
    exit(1);
  }
  // while loop to allow user to keep analyzing files until they are finished
  while(user)
  {
      // iterating through each line
      while(getline(inputStreamer, line))
      {
        //incrementing lineCount in each iteration
        lineCount++;
        // iterating through each letter in a line
        for (int i = 0; i < line.length(); i++)
        {

          dna = tolower(line[i]); // taking each letter, setting it to the variable dna and converting it to a standard lowercase letter
          dna1 = tolower(line[i+1]); // making the letter after i, lowercased to compare biagrams
          //checking nucleotides and adding to its count variables
          if(dna == 'a')
          {
            countA++;
            //checking for biagrams and adding to their count variables
            if(dna1 == 'a'){
              aa++;
              countBigram++;
            }
            else if(dna1 == 'c'){
              ac++;
              countBigram++;
            }
            else if(dna1 == 't'){
              at++;
              countBigram++;
            }
            else if(dna1 == 'g'){
              ag++;
              countBigram++;
            }
          }
          if(dna == 'c')
          {
            countC++;
            if(dna1 == 'a'){
              ca++;
              countBigram++;
            }
            else if(dna1 == 'c'){
              cc++;
              countBigram++;
            }
            else if(dna1 == 't'){
              ct++;
              countBigram++;
            }
            else if(dna1 == 'g'){
              cg++;
              countBigram++;
            }
          }
          if(dna == 't')
          {
            countT++;
            if(dna1 == 'a'){
              ta++;
              countBigram++;
            }
            else if(dna1 == 'c'){
              tc++;
              countBigram++;
            }
            else if(dna1 == 't'){
              tt++;
              countBigram++;
            }
            else if(dna1 == 'g'){
              tg++;
              countBigram++;
            }
          }
          if(dna == 'g')
          {
            countG++;
            if(dna1 == 'a'){
              ga++;
              countBigram++;
            }
            else if(dna1 == 'c'){
              gc++;
              countBigram++;
            }
            else if(dna1 == 't'){
              gt++;
              countBigram++;
            }
            else if(dna1 == 'g'){
              gg++;
              countBigram++;
            }
          }


        }
        // adding the number of nucleotides to the DNAsum
        DNAsum += line.length();
      }

    //closing inputStreamer
    inputStreamer.close();

    //printing data to the outputStreamer file
    outputStreamer << "SANIYA SYED" << endl;
    outputStreamer << "STUDENT ID: 2325873" << endl;
    outputStreamer << "DATA STRUCTURES: SECTION 3" << endl;
    outputStreamer << "PROGRAMMING ASSIGNMENT 1" << endl;
    outputStreamer << endl;

    outputStreamer << "FILE NAME: " << fileName << endl;
    outputStreamer << "LINE COUNT: " << lineCount << endl;
    outputStreamer << "TOTAL NUCLEOTIDES: " << DNAsum << endl;
    outputStreamer << "A COUNT: " << countA << endl;
    outputStreamer << "C COUNT: " << countC << endl;
    outputStreamer << "T COUNT: "<< countT << endl;
    outputStreamer << "G COUNT: "<< countG << endl;
    outputStreamer << "TOTAL BIGRAM COUNT: "<< countBigram << endl;
    outputStreamer << endl;
    // Displaying Bigram Counts
    outputStreamer << "BIGRAM COUNTS:" << endl;
    outputStreamer << "AA COUNT: " << aa << endl;
    outputStreamer << "CC COUNT: " << cc << endl;
    outputStreamer << "TT COUNT: " << tt << endl;
    outputStreamer << "GG COUNT: " << gg << endl;
    outputStreamer << "AC COUNT: " << ac << endl;
    outputStreamer << "AT COUNT: " << at << endl;
    outputStreamer << "AG COUNT: " << ag << endl;
    outputStreamer << "CA COUNT: " << ca << endl;
    outputStreamer << "CT COUNT: " << ct << endl;
    outputStreamer << "CG COUNT: " << cg << endl;
    outputStreamer << "TA COUNT: " << ta << endl;
    outputStreamer << "TC COUNT: " << tc << endl;
    outputStreamer << "TG COUNT: " << tg << endl;
    outputStreamer << "GA COUNT: " << ga << endl;
    outputStreamer << "GC COUNT: " << gc << endl;
    outputStreamer << "GT COUNT: " << gt << endl;
    outputStreamer << endl;

    //Displaying probability for each nucleotide and bigram
    outputStreamer << "PROBABILITIES: " << endl;
    outputStreamer << "PROBABILITY OF A: " << countA / DNAsum * 100 << "%" << endl;
    outputStreamer << "PROBABILITY OF C: " << countC / DNAsum * 100 << "%" << endl;
    outputStreamer << "PROBABILITY OF T: " << countT / DNAsum * 100 << "%" << endl;
    outputStreamer << "PROBABILITY OF G: " << countG / DNAsum * 100 << "%" << endl;
    outputStreamer << "PROBABILITY OF AA: " << aa / countBigram * 100 << "%" << endl;
    outputStreamer << "PROBABILITY OF CC: " << cc / countBigram * 100 << "%" << endl;
    outputStreamer << "PROBABILITY OF TT: " << tt / countBigram * 100 << "%" << endl;
    outputStreamer << "PROBABILITY OF GG: " << gg / countBigram * 100 << "%" << endl;
    outputStreamer << "PROBABILITY OF AC: " << ac / countBigram * 100 << "%" << endl;
    outputStreamer << "PROBABILITY OF AT: " << at / countBigram * 100 << "%" << endl;
    outputStreamer << "PROBABILITY OF AG: " << ag / countBigram * 100 << "%" << endl;
    outputStreamer << "PROBABILITY OF CA: " << ca / countBigram * 100 << "%" << endl;
    outputStreamer << "PROBABILITY OF CT: " << ct / countBigram * 100 << "%" << endl;
    outputStreamer << "PROBABILITY OF CG: " << cg / countBigram * 100 << "%" << endl;
    outputStreamer << "PROBABILITY OF TA: " << ta / countBigram * 100 << "%" << endl;
    outputStreamer << "PROBABILITY OF TC: " << tc / countBigram * 100 << "%" << endl;
    outputStreamer << "PROBABILITY OF TG: " << tg / countBigram * 100 << "%" << endl;
    outputStreamer << "PROBABILITY OF GA: " << ga / countBigram * 100 << "%" << endl;
    outputStreamer << "PROBABILITY OF GC: " << gc / countBigram * 100 << "%" << endl;
    outputStreamer << "PROBABILITY OF GT: " << gt / countBigram * 100 << "%" << endl;

    outputStreamer << endl;

    // Outputting mean, variance, standard deviation, and gaussian value
    calcMean();
    calcVarStdev(fileName);
    outputStreamer << "GAUSSIAN VALUE: " << calcGaussian() << endl;

    // Calculating probability for each nucleotide
    float aProb = countA / DNAsum;
    float cProb = countC / DNAsum;
    float gProb = countG / DNAsum;
    float tProb = countT / DNAsum;

    //iterating up to 1000 to append all the lines
    for(int i = 0; i < 1000; ++i)
    {
      d = calcGaussian();
      // finding how many of each nucleotide that we need
      aNeed = d * aProb;
      cNeed = d * cProb;
      gNeed = d * gProb;
      tProb = d * tProb;

      //creating new variable for the 1000 line string
      string appendedString = "";

      //appending each nucleotide that we need to the new string
      for(int j = 0; j < aNeed; ++j)
      {
        appendedString += "a";
      }
      for(int k = 0; k < cNeed; ++k)
      {
        appendedString += "c";
      }
      for(int l = 0; l < gNeed; ++l)
      {
        appendedString += "g";
      }
      for(int m = 0; m < tNeed; ++m)
      {
        appendedString += "t";
      }
      // outputting the string
      outputStreamer << appendedString << endl;

    }
    outputStreamer << endl;
    outputStreamer << endl;


    //indicating successful analysis
    cout << fileName << " has been analyzed. " << endl;
    // asking user if they would like to input another file
    cout << "Would you like to input another file? ('y' or 'n'): " << endl;
    cin >> userChoice;
    if(userChoice == 'y' || userChoice == 'Y')
    {

      cout << "Enter the name of the next file you would like to analyze: ";
      cin >> fileName;
      ifstream inputStreamer;
      //opening new file into inputStreamer
      inputStreamer.open(fileName);
      // checking if file is valid
      if(!inputStreamer)
      {
        cerr << "Unable to open " << fileName << endl;
        exit(1);
      }
    }
    // exiting out of loop to end program
    else
    {
        user = false;
    }

    //resetting all count variables to 0 for the next file
    line = "";
    countA = 0;
    countC = 0;
    countT = 0;
    countG = 0;
    DNAsum = 0;
    aa = 0, cc = 0, tt = 0, gg = 0;
    ac = 0, at = 0, ag = 0;
    ca = 0, ct = 0, cg = 0;
    ta = 0, tc = 0, tg = 0;
    ga = 0, gc = 0, gt = 0;
    countBigram = 0;
    lineCount = 0;


  }
  //closing outputStreamer
  outputStreamer.close();
}
