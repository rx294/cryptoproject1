key_chars = {}
ciphertext = []
offset = {}
key = {}
unit_freq_char_position_lists = []


charlist = [" ",'a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z']
charfreq = [19, 7, 1, 2, 4, 10, 2, 2, 5, 6, 1, 1, 3, 2, 6, 6, 2, 1, 5, 5, 7, 2, 1, 2, 1, 2, 1]

#generate char-frequency map
for i in 0...charlist.count
  key_chars[charlist[i]] = charfreq[i]
end

plaintext = [
  'dipped ligatured cannier cohabitation cuddling coiffeuses pursuance roper eternizes nullo framable paddlings femur bebop demonstrational tuberculoid theocracy women reappraise oblongatae aphasias loftiness consumptive lip neurasthenically dutchmen grift discredited resourcefulness malfeasants swallowed jogger sayable lewder editorials demimondaine tzaritza arrogations wish indisputable reproduces hygrometries gamuts alight borderlines draggle reconsolidated anemometer rowels staggerers grands nu',
  'rereads predestines equippers cavitation bimolecular lucubrations cabin bettas quiverer prussians cosigner dressier bended dethronement inveigled davenport establish ganges rebroadcast supered bastiles willable abetted motionlessness demonic flatter bunyan securely tippiest tongue aw cotyledonal roomettes underlies miffs inducement overintellectually fertilize spasmodic bacchanal birdbrains decoct snakebite galliard boson headmistress unextended provence weakling pirana fiend lairds argils comma',
  'trawling responsiveness tastiest pulsed restamps telescoping pneuma lampoonist divas theosophists pustules checkrowed compactor conditionals envy hairball footslogs wasteful conjures deadfall stagnantly procure barked balmier bowery vagary beaten capitalized undersized towpath envisages thermoplastic rationalizers professions workbench underarm trudger icicled incisive oilbirds citrins chambrays ungainliness weazands prehardened dims determinants fishskin cleanable henceforward misarranges fine',
  'dean iller playbooks resource anesthetic credibilities nonplus tzetzes incursions stooged envelopments girdling risibility thrum repeaters catheterizing misbestowed cursing malingerers ensconces lippiest accost superannuate slush opinionated rememberer councils mishandling drivels juryless slashers tangent roistering scathing apprenticing fleabite sault achier quantize registrable nobbler sheaf natantly kashmirs dittoes scanned emissivity iodize dually refunded portliest setbacks eureka needines',
  'mammate punners octette asylum nonclinically trotters slant collocation cardiology enchants ledge deregulated bottommost capsulate biotechnologies subtended cloddiest training joneses catafalque fieldmice hostels affect shrimper differentiations metacarpus amebas sweeter shiatsu oncoming tubeless menu professing apostatizing moreover eumorphic casked euphemistically programmability campaniles chickpea inactivates crossing defoggers reassures tableland doze reassembled striate precocious noncomba'
]

#generate character map for chars with unit frequencies
for l in 0...plaintext.length
  ['b','j','k','q','x','z'].each do |char|
    for i in 0...plaintext[l].length
      if plaintext[l][i].eql?(char)
        unit_freq_char_position_lists[l] = {} if unit_freq_char_position_lists[l].nil?
        unit_freq_char_position_lists[l][char] = [] if unit_freq_char_position_lists[l][char].nil?
        unit_freq_char_position_lists[l][char].push(i)
      end
    end
  end
end


# puts unit_freq_char_position_lists

#generate random key
key_chars.keys.each do |char|
	for i in 1..key_chars[char]
		key[char] = [] if key[char].nil?
		key[char].push(Random.new.rand(0..105) )
	end
end

# randomly pick one of the plaintexts to encrypt
random_pick = rand(0...5)
ciphertext = []

# encrypt chosen plaintext
for i in 0...plaintext[random_pick].length
  offset[plaintext[random_pick][i]] = -1 if offset[plaintext[random_pick][i]].nil?
  offset[plaintext[random_pick][i]] = (offset[plaintext[random_pick][i]]+1) % key[plaintext[random_pick][i]].count
  ciphertext.push(key[plaintext[random_pick][i]][offset[plaintext[random_pick][i]]])
end

puts ciphertext.to_s

# try to decode using unit frequency chars
right_plaintext_index = -1
for l in 0...unit_freq_char_position_lists.length
  current_list = unit_freq_char_position_lists[l]
  current_list.keys.each do |key|
    arr = []
    current_list[key].each do |pos|
      arr.push(ciphertext[pos])
    end unless current_list[key].length < 2
    if arr.uniq.length == 1
      right_plaintext_index = l
    end
  end
end

if right_plaintext_index < 0 
  puts "Could not decode the cipher text :( "
else
  puts "random plaintext picked====>", plaintext[random_pick]
  puts "-------------------------------------------"
  puts right_plaintext_index
  puts "decoded cipher text====>",plaintext[right_plaintext_index]
end


# plaintext = [
# "brisking",
# "cottoned",
# "dextrins",
# "energize",
# "expatiations",
# "finale",
# "freelancing",
# "gibbousness",
# "hope",
# "jeopardous",
# "maturates",
# "meaningless",
# "nested",
# "nymphal",
# "rankly",
# "sampling",
# "stovepipes",
# "swells",
# "travestied",
# "violators",
# ]

# plaintext = plaintext.sort_by {|x| x.length}


# puts plaintext.length

# for l in 0...plaintext.length
#   ['b','j','k','q','x','z'].each do |char|
#     for i in 0...plaintext[l].length
#       if plaintext[l][i].eql?(char)
#         unit_freq_char_position_lists[l] = {} if unit_freq_char_position_lists[l].nil?
#         unit_freq_char_position_lists[l][char] = [] if unit_freq_char_position_lists[l][char].nil?
#         unit_freq_char_position_lists[l][char].push(i)
#       end
#     end
#   end
# end

# puts 

# i=0

# plaintext.each do |p|
#   puts p, p.length
#   puts unit_freq_char_position_lists[i]
#   i=i+1
# end


