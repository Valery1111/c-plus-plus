#include <iostream>
#include <mutex>
#include <thread>
#include <vector>
#include <string>
#include <algorithm>
#include <functional>

template <typename T>
inline void PRINT_ELEMENTS (const T& coll,
                            const std::string& optstr="",
							const std::string& delim=" ")
{
    std::cout << optstr;
    for (const auto&  elem : coll) {
        std::cout << elem << delim;
    }
    std::cout << std::endl;
}

using namespace std;

const size_t SEQ_LENGTH = 10000;
mutex pvmutex;

string random_DNA_str( size_t length )
{
    auto randchar = []() -> char
    {
        const char charset[] = "AGTC";
        const size_t max_index = (sizeof(charset) - 1);
        return charset[ rand() % max_index ];
    };
    string str(length,0);
    generate_n( str.begin(), length, randchar );
    return str;
}

void save_position(vector<size_t>& positions, size_t pos, const string& seq, const string& subseq)
{
	size_t seq_len = seq.size();
	size_t subseq_len = subseq.size();
	size_t i = 0;

	while (pos < seq_len && i < subseq_len)
	{
		if(seq[pos] != subseq[i])
		{
			break;
		}
		++i;
		++pos;
	}
	if(i >= subseq_len)
	{
		lock_guard<mutex> lg(pvmutex);
		positions.push_back(pos - subseq_len);
	}
}

void find_all_entries(vector<size_t>& positions, string& seq, string& subseq)
{
	vector<thread> threads;

	size_t seq_len = seq.size();
	for (size_t i = 0; i < seq_len; ++i)
	{
		if(seq[i] == subseq[0])
		{
			threads.push_back(std::thread(save_position, std::ref(positions), i,
					std::ref(seq), std::ref(subseq)));
		}
	}
	std::for_each(threads.begin(), threads.end(), std::mem_fn(&std::thread::join));
}

int main() {
	string DNA_seq = random_DNA_str(SEQ_LENGTH);
	cout << "DNA sequence for " << SEQ_LENGTH << " elements\n";
	PRINT_ELEMENTS(DNA_seq, "", "");

	string seq;
	cout << "Enter the sequence from A, G, T, C elements: ";
	cin >> seq;

	vector<size_t> positions;
	find_all_entries(positions, DNA_seq, seq);
	PRINT_ELEMENTS(positions, "Positions: ", ", ");

	cout << positions.size() << " positions found\n";

	return 0;
}

