// Decrypter.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
#include <sstream>
#include <time.h>


using namespace std;

vector<string> plaintexts;
vector<int> ciphertext;

vector<unordered_map<char, std::vector<int> > > unitCharMapList;
unordered_map<char, std::vector<int> > unitCharMap;


void PopulatePlaintexts()
{
	plaintexts.push_back("dipped ligatured cannier cohabitation cuddling coiffeuses pursuance roper eternizes nullo framable paddlings femur bebop demonstrational tuberculoid theocracy women reappraise oblongatae aphasias loftiness consumptive lip neurasthenically dutchmen grift discredited resourcefulness malfeasants swallowed jogger sayable lewder editorials demimondaine tzaritza arrogations wish indisputable reproduces hygrometries gamuts alight borderlines draggle reconsolidated anemometer rowels staggerers grands nu");
	plaintexts.push_back("rereads predestines equippers cavitation bimolecular lucubrations cabin bettas quiverer prussians cosigner dressier bended dethronement inveigled davenport establish ganges rebroadcast supered bastiles willable abetted motionlessness demonic flatter bunyan securely tippiest tongue aw cotyledonal roomettes underlies miffs inducement overintellectually fertilize spasmodic bacchanal birdbrains decoct snakebite galliard boson headmistress unextended provence weakling pirana fiend lairds argils comma");
	plaintexts.push_back("trawling responsiveness tastiest pulsed restamps telescoping pneuma lampoonist divas theosophists pustules checkrowed compactor conditionals envy hairball footslogs wasteful conjures deadfall stagnantly procure barked balmier bowery vagary beaten capitalized undersized towpath envisages thermoplastic rationalizers professions workbench underarm trudger icicled incisive oilbirds citrins chambrays ungainliness weazands prehardened dims determinants fishskin cleanable henceforward misarranges fine");
	plaintexts.push_back("dean iller playbooks resource anesthetic credibilities nonplus tzetzes incursions stooged envelopments girdling risibility thrum repeaters catheterizing misbestowed cursing malingerers ensconces lippiest accost superannuate slush opinionated rememberer councils mishandling drivels juryless slashers tangent roistering scathing apprenticing fleabite sault achier quantize registrable nobbler sheaf natantly kashmirs dittoes scanned emissivity iodize dually refunded portliest setbacks eureka needines");
	plaintexts.push_back("mammate punners octette asylum nonclinically trotters slant collocation cardiology enchants ledge deregulated bottommost capsulate biotechnologies subtended cloddiest training joneses catafalque fieldmice hostels affect shrimper differentiations metacarpus amebas sweeter shiatsu oncoming tubeless menu professing apostatizing moreover eumorphic casked euphemistically programmability campaniles chickpea inactivates crossing defoggers reassures tableland doze reassembled striate precocious noncomba");
}

//Generate Character Map for characters with unit frequency
void Generatemapforunitfrequency()
{
	char unitFreqChars[] = { 'b', 'j', 'k', 
		'v', 'q', 'x', 'z' };

	for (int l = 0; l < plaintexts.size(); l++) {
		for (int j = 0; j < sizeof(unitFreqChars) / sizeof(unitFreqChars[0]); j++) {
			for (int i = 0; i < plaintexts[l].length(); i++) {
				if (plaintexts[l][i] == unitFreqChars[j]) {
					unitCharMap[unitFreqChars[j]].push_back(i);
				}
			}
		}
		unitCharMapList.push_back(unitCharMap);
		unitCharMap.clear();
	}
}

int DecryptCiphertext()
{
	for (int l = 0; l < unitCharMapList.size(); l++) {
		for (auto it = unitCharMapList[l].begin(); it != unitCharMapList[l].end(); ++it) {
			vector<int> positions;

			for (int i = 0; i < unitCharMapList[l][it->first].size(); ++i) {
				if (unitCharMapList[l][it->first][i] <= ciphertext.size())
					positions.push_back(ciphertext[unitCharMapList[l][it->first][i]]);
			}

			if (positions.size() > 1 && equal(positions.begin() + 1, positions.end(), positions.begin())) {
				return l;
			}
			positions.clear();

		}
	}
	return -1;
}

int main()
{
	PopulatePlaintexts();
	Generatemapforunitfrequency();


	//    Test cipher text below should match to plaintext starting mammate punners...
	// ciphertext = {72, 20, 89, 72, 87, 38, 48, 89, 58, 39, 66, 7, 12, 79, 29, 104, 71, 36, 69, 4, 13, 81, 4, 80, 7, 77, 89, 77, 63, 89, 17, 25, 51, 35, 59, 56, 15, 81, 62, 36, 83, 15, 77, 36, 40, 15, 68, 69, 68, 11, 4, 47, 47, 64, 32, 56, 48, 19, 38, 23, 59, 1, 15, 77, 21, 36, 48, 69, 92, 47, 66, 12, 59, 18, 93, 60, 79, 71, 56, 51, 45, 89, 6, 86, 7, 36, 2, 20, 25, 13, 22, 19, 15, 70, 30, 43, 20, 81, 105, 18, 61, 50, 45, 39, 77, 87, 81, 48, 45, 84, 13, 69, 15, 68, 1, 72, 89, 21, 29, 11, 37, 59, 7, 58, 77, 63, 56, 83, 38, 12, 50, 13, 32, 47, 69, 4, 36, 99, 35, 71, 15, 51, 43, 2, 4, 47, 39, 32, 39, 13, 13, 4, 81, 60, 86, 30, 7, 59, 77, 69, 105, 45, 15, 70, 22, 81, 64, 15, 79, 48, 62, 19, 92, 66, 45, 15, 68, 1, 7, 20, 29, 18, 77, 71, 36, 48, 68, 18, 81, 20, 56, 62, 63, 50, 89, 96, 79, 48, 15, 60, 72, 32, 59, 12, 104, 69, 21, 47, 11, 4, 77, 32, 80, 87, 81, 96, 4, 36, 38, 17, 22, 32, 68, 2, 89, 58, 4, 47, 40, 30, 15, 81, 96, 86, 93, 70, 25, 69, 62, 7, 13, 92, 47, 35, 29, 64, 72, 20, 81, 83, 59, 48, 61, 58, 39, 77, 23, 48, 89, 18, 13, 18, 47, 12, 32, 52, 50, 48, 15, 12, 79, 6, 22, 70, 79, 20, 68, 29, 63, 19, 71, 81, 36, 51, 72, 32, 19, 43, 81, 11, 39, 13, 4, 56, 4, 77, 47, 84, 89, 4, 66, 63, 37, 58, 68, 69, 81, 86, 32, 22, 2, 7, 45, 50, 87, 58, 1, 29, 38, 7, 69, 15, 104, 62, 25, 43, 39, 72, 21, 47, 70, 47, 65, 20, 93, 7, 18, 39, 89, 71, 61, 58, 2, 92, 59, 64, 36, 83, 77, 60, 50, 105, 15, 48, 63, 58, 99, 12, 72, 79, 47, 13, 32, 59, 48, 15, 77, 36, 71, 58, 79, 51, 45, 68, 48, 89, 72, 18, 13, 2, 56, 15, 81, 89, 89, 36, 20, 89, 58, 87, 35, 62, 15, 4, 32, 104, 59, 69, 92, 36, 60, 58, 4, 7, 80, 79, 81, 83, 59, 15, 32, 65, 48, 68, 4, 22, 17, 36, 47, 69, 29, 77, 2, 19, 43, 40, 45, 86, 96, 1, 45, 43, 70, 93, 47, 64, 61, 20, 48, 32, 22, 39, 79, 18, 29, 23, 11, 18, 13, 77, 50, 56, 20, 66, 60, 12, 30, 21, 104, 48, 6, 68, 12, 87, 77, 47, 4, 72, 13, 15, 4, 105, 19, 32, 38, 47, 15, 7, 69, 4, 81, 58, 93, 86, 59, 47, 36, 62, 71, 63, 22, 84, 7, 51, 25, 59, 69, 89, 13, 83};

	string mycipher;

	cout << "Enter the ciphertext : ";
	getline(cin, mycipher);
	stringstream ss(mycipher);
	string i;
	while (ss >> i)
	{
		ciphertext.push_back(stoi(i));
		if (ss.peek() == ',')
		{
			ss.ignore();
		}
		
	}

	const clock_t begin_time = clock();
	int right_plaintext_index = DecryptCiphertext();

	if (right_plaintext_index < 0)
	{
		cout << "Could not decode ciphertext" << endl;
	}
	else
	{
		cout << "\n\nDecrypted Plaintext guess:\n\n" << endl << plaintexts[right_plaintext_index] <<endl<<endl;
	}
	cout << "Duration: "<<float(clock() - begin_time) / CLOCKS_PER_SEC << " seconds" <<endl;

	system("pause");
	return 0;
}
