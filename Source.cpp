#include<iostream>
#include<string>
#include<vector>
#include<time.h>
#include <stdlib.h>


using namespace std;


class BigNum 
{
private:
	string numb;
	vector<int> sum;
	vector<int> razn;
	vector<int> umn;
	vector<int> del;
	
public:
	BigNum()
	{
		this->numb;
	}
	
	friend istream& operator >>(istream& is, BigNum& num)
	{
		is >> num.numb;
		return is;
	}
	friend ostream& operator <<(ostream& os, const BigNum& num)
	{
		os << num.numb;
		return os;
	}
	BigNum operator + ( BigNum num2)
	{
		BigNum z;
		string a = this->numb;
		string b = num2.numb;
		string el;
		string rez;
		vector<int> num_1;
		vector<int> num_2;

		for (int i = 0; i < a.size(); i++)
		{
			if (a[i] == '-' || a[i] == '0' || a[i] == '1' || a[i] == '2' || a[i] == '3' || a[i] == '4' || a[i] == '5' || a[i] == '6' ||
				a[i] == '7' || a[i] == '8' || a[i] == '9')
			{
				if (a[0] == '0'&&a.size() != 1)
				{
					cout << "The number entered is incorrect" << endl;
					return z;
				}
				else if (i != 0 && a[i] == '-')
				{
					cout << "The number entered is incorrect" << endl;
					return z;
				}
			}
			else
			{
				cout << "The number entered is incorrect" << endl;
				return z;
			}
		}
		for (int i = 0; i < b.size(); i++)
		{
			if (b[i] == '-' || b[i] == '0' || b[i] == '1' || b[i] == '2' || b[i] == '3' || b[i] == '4' || b[i] == '5' || b[i] == '6' ||
				b[i] == '7' || b[i] == '8' || b[i] == '9')
			{
				if (b[0] == '0' && b.size() != 1)
				{
					cout << "The number entered is incorrect" << endl;
					return z;
				}
				else if (i != 0 && b[i] == '-')
				{
					cout << "The number entered is incorrect" << endl;
					return z;
				}
			}
			else
			{
				cout << "The number entered is incorrect" << endl;
				return z;
			}
		}
		if (a[0] == '-' || b[0] == '-')  //имеют ли минус
		{
			if (a[0] == '-' && b[0] == '-')
			{
				if (a[1] == '0' && b[1] == '0')
				{
					z.numb = '0';
					return z;
				}
				a = a.substr(1);
				b = b.substr(1);
				for (int i = 0; i < a.size(); i++)
				{
					num_1.push_back(atoi(a.substr(i, 1).c_str()));
				}

				for (int j = 0; j < b.size(); j++)
				{
					num_2.push_back(atoi(b.substr(j, 1).c_str()));
				}

				if (num_1.size() >= num_2.size())
				{
					while (sum.size() != num_1.size())
					{
						sum.push_back(0);
					}
					while (num_1.size() != num_2.size())
					{
						vector<int>::iterator itIns = num_2.begin();
						num_2.insert(itIns, 0);
					}

					for (int k = num_1.size() - 1; k >= 0; k--)
					{
						string elem;
						vector<int>keepone;
						sum[k] = num_1[k] + num_2[k];

						if (sum[k] > 9)
						{
							if (k != 0)
							{
								elem = to_string(sum[k]);
								sum[k] = 0;
								sum[k] = atoi(elem.substr(1).c_str());
								keepone.push_back(atoi(elem.substr(0, 1).c_str()));
								k--;
								num_1[k] = num_1[k] + keepone[0];
								k++;
							}

						}

					}
					rez.push_back('-');
					for (int i = 0; i < sum.size(); i++)
					{
						el = to_string(sum[i]);
						for (int j = 0; j < el.size(); j++)
						{
							rez.push_back(el[j]);
						}
					}
					z.numb = rez;
					return z;
				}
				else if (num_2.size() > num_1.size())
				{
					while (sum.size() != num_2.size())
					{
						sum.push_back(0);
					}
					while (num_2.size() != num_1.size())
					{
						vector<int>::iterator itIns = num_1.begin();
						num_1.insert(itIns, 0);
					}

					for (int k = num_2.size() - 1; k >= 0; k--)
					{
						string elem;
						vector<int>keepone;
						sum[k] = num_2[k] + num_1[k];

						if (sum[k] > 9)
						{
							if (k != 0)
							{
								elem = to_string(sum[k]);
								sum[k] = 0;
								sum[k] = atoi(elem.substr(1).c_str());
								keepone.push_back(atoi(elem.substr(0, 1).c_str()));
								k--;
								num_2[k] = num_2[k] + keepone[0];
								k++;
							}

						}

					}
					rez.push_back('-');
					for (int i = 0; i < sum.size(); i++)
					{
						el = to_string(sum[i]);
						for (int j = 0; j < el.size(); j++)
						{
							rez.push_back(el[j]);
						}
					}
					z.numb = rez;
					return z;
				}
			}
			else
			{
				if (a[0] == '-')  //имеет ли первое число минус
				{
					a = a.substr(1);
					
					if (a.size() > b.size())
					{
						for (int i = 0; i < a.size(); i++)
						{
							num_1.push_back(atoi(a.substr(i, 1).c_str()));
						}

						for (int j = 0; j < b.size(); j++)
						{
							num_2.push_back(atoi(b.substr(j, 1).c_str()));
						}
						while (sum.size() != num_1.size())
						{
							sum.push_back(0);
						}
						while (num_1.size() != num_2.size())
						{
							vector<int>::iterator itIns = num_2.begin();
							num_2.insert(itIns, 0);
						}
						for (int i = num_1.size() - 1; i >= 0; i--)
						{
							string elem;
							vector<int>keepone;
							if (num_1[i] >= num_2[i])
							{
								sum[i] = num_1[i] - num_2[i];
							}
							else if (num_1[i] < num_2[i])
							{
								num_1[i] = num_1[i] + 10;
								i--;
								while (num_1[i] == 0)
								{
									num_1[i] = num_1[i] + 9;
									i--;
								}
								num_1[i] = num_1[i] - 1;
								i++;
								while (num_1[i] == 9)
								{
									i++;
								}
								sum[i] = num_1[i] - num_2[i];

							}
						}
						rez.push_back('-');
						if (sum[0] == 0)
						{
							vector<int>::iterator Era = sum.begin();
							sum.erase(Era);
						}
						for (int i = 0; i < sum.size(); i++)
						{
							el = to_string(sum[i]);
							for (int j = 0; j < el.size(); j++)
							{
								rez.push_back(el[j]);
							}
						}
						z.numb = rez;
						return z;
					}
					else if (a.size() < b.size())
					{
						for (int i = 0; i < a.size(); i++)
						{
							num_1.push_back(atoi(a.substr(i, 1).c_str()));
						}

						for (int j = 0; j < b.size(); j++)
						{
							num_2.push_back(atoi(b.substr(j, 1).c_str()));
						}
						while (sum.size() != num_2.size())
						{
							sum.push_back(0);
						}
						while (num_2.size() != num_1.size())
						{
							vector<int>::iterator itIns = num_1.begin();
							num_1.insert(itIns, 0);
						}
						for (int i = num_2.size() - 1; i >= 0; i--)
						{
							string elem;
							vector<int>keepone;
							if (num_2[i] >= num_1[i])
							{
								sum[i] = num_2[i] - num_1[i];
							}
							else if (num_2[i] < num_1[i])
							{
								num_2[i] = num_2[i] + 10;
								i--;
								while (num_2[i] == 0)
								{
									num_2[i] = num_2[i] + 9;
									i--;
								}
								num_2[i] = num_2[i] - 1;
								i++;
								while (num_2[i] == 9)
								{
									i++;
								}
								sum[i] = num_2[i] - num_1[i];

							}
						}
						
						if (sum[0] == 0)
						{
							vector<int>::iterator Era = sum.begin();
							sum.erase(Era);
						}
						for (int i = 0; i < sum.size(); i++)
						{
							el = to_string(sum[i]);
							for (int j = 0; j < el.size(); j++)
							{
								rez.push_back(el[j]);
							}
						}
						z.numb = rez;
						return z;
					}
					else if (a.size() == b.size())
					{
						for (int i = 0; i < a.size(); i++)
						{
							num_1.push_back(atoi(a.substr(i, 1).c_str()));
						}

						for (int j = 0; j < b.size(); j++)
						{
							num_2.push_back(atoi(b.substr(j, 1).c_str()));
						}
						while (sum.size() != num_2.size())
						{
							sum.push_back(0);
						}
						bool chek = num_1 == num_2;
						if (chek == 1)
						{
							sum.clear();
							sum.push_back(0);
							for (int i = 0; i < sum.size(); i++)
							{
								el = to_string(sum[i]);
								for (int j = 0; j < el.size(); j++)
								{
									rez.push_back(el[j]);
								}
							}
							z.numb = rez;
							return z;
						}
						else if (chek == 0)
						{
							for (int c = 0; num_1.size(); c++)
							{

								if (num_1[c] > num_2[c] || num_2[c] > num_1[c])
								{
									if (num_1[c] > num_2[c])
									{
										for (int i = num_1.size() - 1; i >= 0; i--)
										{
											string elem;
											vector<int>keepone;
											if (num_1[i] >= num_2[i])
											{
												sum[i] = num_1[i] - num_2[i];
											}
											else if (num_1[i] < num_2[i])
											{
												num_1[i] = num_1[i] + 10;
												i--;
												while (num_1[i] == 0)
												{
													num_1[i] = num_1[i] + 9;
													i--;
												}
												num_1[i] = num_1[i] - 1;
												i++;
												while (num_1[i] == 9)
												{
													i++;
												}
												sum[i] = num_1[i] - num_2[i];

											}
										}
										rez.push_back('-');
										if (sum[0] == 0)
										{
											vector<int>::iterator Era = sum.begin();
											sum.erase(Era);
										}
										for (int i = 0; i < sum.size(); i++)
										{
											el = to_string(sum[i]);
											for (int j = 0; j < el.size(); j++)
											{
												rez.push_back(el[j]);
											}
										}
										z.numb = rez;
										return z;
									}
									else
									{
										for (int i = num_2.size() - 1; i >= 0; i--)
										{
											string elem;
											vector<int>keepone;
											if (num_2[i] >= num_1[i])
											{
												sum[i] = num_2[i] - num_1[i];
											}
											else if (num_2[i] < num_1[i])
											{
												num_2[i] = num_2[i] + 10;
												i--;
												while (num_2[i] == 0)
												{
													num_2[i] = num_2[i] + 9;
													i--;
												}
												num_2[i] = num_2[i] - 1;
												i++;
												while (num_2[i] == 9)
												{
													i++;
												}
												sum[i] = num_2[i] - num_1[i];

											}
										}

										if (sum[0] == 0)
										{
											vector<int>::iterator Era = sum.begin();
											sum.erase(Era);
										}
										for (int i = 0; i < sum.size(); i++)
										{
											el = to_string(sum[i]);
											for (int j = 0; j < el.size(); j++)
											{
												rez.push_back(el[j]);
											}
										}
										z.numb = rez;
										return z;
									}
								}

							}
						}
					}
				}
				else                               //≈сли первое false, значит второе число имеет минус
				{
					if (b[1] == '0')
					{
						z.numb = a;
						return z;
					}
					b = b.substr(1);
					if (a.size() > b.size())
					{
						for (int i = 0; i < a.size(); i++)
						{
							num_1.push_back(atoi(a.substr(i, 1).c_str()));
						}

						for (int j = 0; j < b.size(); j++)
						{
							num_2.push_back(atoi(b.substr(j, 1).c_str()));
						}
						while (sum.size() != num_1.size())
						{
							sum.push_back(0);
						}
						while (num_1.size() != num_2.size())
						{
							vector<int>::iterator itIns = num_2.begin();
							num_2.insert(itIns, 0);
						}
						for (int i = num_1.size() - 1; i >= 0; i--)
						{
							string elem;
							vector<int>keepone;
							if (num_1[i] >= num_2[i])
							{
								sum[i] = num_1[i] - num_2[i];
							}
							else if (num_1[i] < num_2[i])
							{
								num_1[i] = num_1[i] + 10;
								i--;
								while (num_1[i] == 0)
								{
									num_1[i] = num_1[i] + 9;
									i--;
								}
								num_1[i] = num_1[i] - 1;
								i++;
								while (num_1[i] == 9)
								{
									i++;
								}
								sum[i] = num_1[i] - num_2[i];

							}
						}
						if (sum[0] == 0)
						{
							vector<int>::iterator Era = sum.begin();
							sum.erase(Era);
						}
						for (int i = 0; i < sum.size(); i++)
						{
							el = to_string(sum[i]);
							for (int j = 0; j < el.size(); j++)
							{
								rez.push_back(el[j]);
							}
						}
						z.numb = rez;
						return z;
					}
					else if (a.size() < b.size())
					{
						for (int i = 0; i < a.size(); i++)
						{
							num_1.push_back(atoi(a.substr(i, 1).c_str()));
						}

						for (int j = 0; j < b.size(); j++)
						{
							num_2.push_back(atoi(b.substr(j, 1).c_str()));
						}
						while (sum.size() != num_2.size())
						{
							sum.push_back(0);
						}
						while (num_2.size() != num_1.size())
						{
							vector<int>::iterator itIns = num_1.begin();
							num_1.insert(itIns, 0);
						}
						for (int i = num_2.size() - 1; i >= 0; i--)
						{
							string elem;
							vector<int>keepone;
							if (num_2[i] >= num_1[i])
							{
								sum[i] = num_2[i] - num_1[i];
							}
							else if (num_2[i] < num_1[i])
							{
								num_2[i] = num_2[i] + 10;
								i--;
								while (num_2[i] == 0)
								{
									num_2[i] = num_2[i] + 9;
									i--;
								}
								num_2[i] = num_2[i] - 1;
								i++;
								while (num_2[i] == 9)
								{
									i++;
								}
								sum[i] = num_2[i] - num_1[i];

							}
						}

						if (sum[0] == 0)
						{
							vector<int>::iterator Era = sum.begin();
							sum.erase(Era);
						}
						rez.push_back('-');
						for (int i = 0; i < sum.size(); i++)
						{
							el = to_string(sum[i]);
							for (int j = 0; j < el.size(); j++)
							{
								rez.push_back(el[j]);
							}
						}
						z.numb = rez;
						return z;
					}
					else if (a.size() == b.size())
					{
						for (int i = 0; i < a.size(); i++)
						{
							num_1.push_back(atoi(a.substr(i, 1).c_str()));
						}

						for (int j = 0; j < b.size(); j++)
						{
							num_2.push_back(atoi(b.substr(j, 1).c_str()));
						}
						while (sum.size() != num_2.size())
						{
							sum.push_back(0);
						}
						bool check = num_1 == num_2;
						if (check == 1)
						{
							sum.clear();
							sum.push_back(0);
							for (int i = 0; i < sum.size(); i++)
							{
								el = to_string(sum[i]);
								for (int j = 0; j < el.size(); j++)
								{
									rez.push_back(el[j]);
								}
							}
							z.numb = rez;
							return z;
						}
						else if (check == 0)
						{
							for (int c = 0; num_1.size(); c++)
							{
								if (num_1[c] > num_2[c] || num_2[c] > num_1[c])
								{
									if (num_1[c] > num_2[c])
									{
										for (int i = num_1.size() - 1; i >= 0; i--)
										{
											string elem;
											vector<int>keepone;
											if (num_1[i] >= num_2[i])
											{
												sum[i] = num_1[i] - num_2[i];
											}
											else if (num_1[i] < num_2[i])
											{
												num_1[i] = num_1[i] + 10;
												i--;
												while (num_1[i] == 0)
												{
													num_1[i] = num_1[i] + 9;
													i--;
												}
												num_1[i] = num_1[i] - 1;
												i++;
												while (num_1[i] == 9)
												{
													i++;
												}
												sum[i] = num_1[i] - num_2[i];

											}
										}
										rez.push_back('-');
										if (sum[0] == 0)
										{
											vector<int>::iterator Era = sum.begin();
											sum.erase(Era);
										}
										for (int i = 0; i < sum.size(); i++)
										{
											el = to_string(sum[i]);
											for (int j = 0; j < el.size(); j++)
											{
												rez.push_back(el[j]);
											}
										}
										z.numb = rez;
										return z;
									}
									else
									{
										for (int i = num_2.size() - 1; i >= 0; i--)
										{
											string elem;
											vector<int>keepone;
											if (num_2[i] >= num_1[i])
											{
												sum[i] = num_2[i] - num_1[i];
											}
											else if (num_2[i] < num_1[i])
											{
												num_2[i] = num_2[i] + 10;
												i--;
												while (num_2[i] == 0)
												{
													num_2[i] = num_2[i] + 9;
													i--;
												}
												num_2[i] = num_2[i] - 1;
												i++;
												while (num_2[i] == 9)
												{
													i++;
												}
												sum[i] = num_2[i] - num_1[i];

											}
										}

										if (sum[0] == 0)
										{
											vector<int>::iterator Era = sum.begin();
											sum.erase(Era);
										}
										for (int i = 0; i < sum.size(); i++)
										{
											el = to_string(sum[i]);
											for (int j = 0; j < el.size(); j++)
											{
												rez.push_back(el[j]);
											}
										}
										z.numb = rez;
										return z;
									}
								}

							}
						}
					}
				}
			}
		}
		else if (a[0] != '-' && b[0] != '-')
		{
			for (int i = 0; i < a.size(); i++)
			{
				num_1.push_back(atoi(a.substr(i, 1).c_str()));
			}

			for (int j = 0; j < b.size(); j++)
			{
				num_2.push_back(atoi(b.substr(j, 1).c_str()));
			}

			if (num_1.size() >= num_2.size())
			{
				while (sum.size() != num_1.size())
				{
					sum.push_back(0);
				}
				while (num_1.size() != num_2.size())
				{
					vector<int>::iterator itIns = num_2.begin();
					num_2.insert(itIns, 0);
				}

				for (int k = num_1.size() - 1; k >= 0; k--)
				{
					string elem;
					vector<int>keepone;
					sum[k] = num_1[k] + num_2[k];

					if (sum[k] > 9)
					{
						if (k != 0)
						{
							elem = to_string(sum[k]);
							
							sum[k] = atoi(elem.substr(1).c_str());
							keepone.push_back(atoi(elem.substr(0, 1).c_str()));
							k--;
							num_1[k] = num_1[k] + keepone[0];
							k++;
						}

					}

				}
				for (int i = 0; i < sum.size(); i++)
				{
					el = to_string(sum[i]);
					for (int j = 0; j < el.size(); j++)
					{
						rez.push_back(el[j]);
					}
				}
				z.numb = rez;
				return z;
			}
			else if (num_2.size() > num_1.size())
			{
				while (sum.size() != num_2.size())
				{
					sum.push_back(0);
				}
				while (num_2.size() != num_1.size())
				{
					vector<int>::iterator itIns = num_1.begin();
					num_1.insert(itIns, 0);
				}

				for (int k = num_2.size() - 1; k >= 0; k--)
				{
					string elem;
					vector<int>keepone;
					sum[k] = num_2[k] + num_1[k];

					if (sum[k] > 9)
					{
						if (k != 0)
						{
							elem = to_string(sum[k]);
							sum[k] = 0;
							sum[k] = atoi(elem.substr(1).c_str());
							keepone.push_back(atoi(elem.substr(0, 1).c_str()));
							k--;
							num_2[k] = num_2[k] + keepone[0];
							k++;
						}

					}

				}
				for (int i = 0; i < sum.size(); i++)
				{
					el = to_string(sum[i]);
					for (int j = 0; j < el.size(); j++)
					{
						rez.push_back(el[j]);
					}
				}
				z.numb = rez;
				return z;
			}
		}
	}
	BigNum operator - (BigNum num2)
	{
		BigNum z;
		string a = this->numb;
		string b = num2.numb;
		string el;
		string rez;
		vector<int> num_1;
		vector<int> num_2;

		for (int i = 0; i < a.size(); i++)
		{
			if (a[i] == '-' || a[i] == '0' || a[i] == '1' || a[i] == '2' || a[i] == '3' || a[i] == '4' || a[i] == '5' || a[i] == '6' ||
				a[i] == '7' || a[i] == '8' || a[i] == '9')
			{
				if (a[0] == '0'&&a.size() != 1)
				{
					cout << "The number entered is incorrect" << endl;
					return z;
				}
				else if (i != 0 && a[i] == '-')
				{
					cout << "The number entered is incorrect" << endl;
					return z;
				}
			}
			else
			{
				cout << "The number entered is incorrect" << endl;
				return z;
			}
		}
		for (int i = 0; i < b.size(); i++)
		{
			if (b[i] == '-' || b[i] == '0' || b[i] == '1' || b[i] == '2' || b[i] == '3' || b[i] == '4' || b[i] == '5' || b[i] == '6' ||
				b[i] == '7' || b[i] == '8' || b[i] == '9')
			{
				if (b[0] == '0' && b.size() != 1)
				{
					cout << "The number entered is incorrect" << endl;
					return z;
				}
				else if (i != 0 && b[i] == '-')
				{
					cout << "The number entered is incorrect" << endl;
					return z;
				}
			}
			else
			{
				cout << "The number entered is incorrect" << endl;
				return z;
			}
		}
		if (a[0] == '-' || b[0] == '-')
		{
			if (a[0] == '-' && b[0] == '-')
			{
				a = a.substr(1);
				b = b.substr(1);
				for (int i = 0; i < a.size(); i++)
				{
					num_1.push_back(atoi(a.substr(i, 1).c_str()));
				}

				for (int j = 0; j < b.size(); j++)
				{
					num_2.push_back(atoi(b.substr(j, 1).c_str()));
				}
				if (num_1.size() > num_2.size())
				{
					while (razn.size() != num_1.size())
					{
						razn.push_back(0);
					}
					while (num_1.size() != num_2.size())
					{
						vector<int>::iterator itIns = num_2.begin();
						num_2.insert(itIns, 0);
					}
					for (int i = num_1.size() - 1; i >= 0; i--)
					{
						string elem;
						vector<int>keepone;
						if (num_1[i] >= num_2[i])
						{
							razn[i] = num_1[i] - num_2[i];
						}
						else if (num_1[i] < num_2[i])
						{
							num_1[i] = num_1[i] + 10;
							i--;
							while (num_1[i] == 0)
							{
								num_1[i] = num_1[i] + 9;
								i--;
							}
							num_1[i] = num_1[i] - 1;
							i++;
							while (num_1[i] == 9)
							{
								i++;
							}
							razn[i] = num_1[i] - num_2[i];

						}
					}
					rez.push_back('-');
					if (razn[0] == 0)
					{
						vector<int>::iterator Era = razn.begin();
						razn.erase(Era);
					}
					for (int i = 0; i < razn.size(); i++)
					{
						el = to_string(razn[i]);
						for (int j = 0; j < el.size(); j++)
						{
							rez.push_back(el[j]);
						}
					}
					z.numb = rez;
					return z;
				}
				else if(num_1.size() < num_2.size())
				{
					while (razn.size() != num_2.size())
					{
						razn.push_back(0);
					}
					while (num_2.size() != num_1.size())
					{
						vector<int>::iterator itIns = num_1.begin();
						num_1.insert(itIns, 0);
					}
					for (int i = num_2.size() - 1; i >= 0; i--)
					{
						string elem;
						vector<int>keepone;
						if (num_2[i] >= num_1[i])
						{
							razn[i] = num_2[i] - num_1[i];
						}
						else if (num_2[i] < num_1[i])
						{
							num_2[i] = num_2[i] + 10;
							i--;
							while (num_2[i] == 0)
							{
								num_2[i] = num_2[i] + 9;
								i--;
							}
							num_2[i] = num_2[i] - 1;
							i++;
							while (num_2[i] == 9)
							{
								i++;
							}
							razn[i] = num_2[i] - num_1[i];

						}
					}

					if (razn[0] == 0)
					{
						vector<int>::iterator Era = razn.begin();
						razn.erase(Era);
					}
					for (int i = 0; i < razn.size(); i++)
					{
						el = to_string(razn[i]);
						for (int j = 0; j < el.size(); j++)
						{
							rez.push_back(el[j]);
						}
					}
					z.numb = rez;
					return z;
				}
				else if (num_2.size() == num_1.size())
				{
					while (razn.size() != num_2.size())
					{
						razn.push_back(0);
					}
					bool chek = num_1 == num_2;
					if (chek == 1)
					{
						razn.clear();
						razn.push_back(0);
						for (int i = 0; i < razn.size(); i++)
						{
							el = to_string(razn[i]);
							for (int j = 0; j < el.size(); j++)
							{
								rez.push_back(el[j]);
							}
						}
						z.numb = rez;
						return z;
					}
					else if (chek == 0)
					{
						for (int c = 0; num_1.size(); c++)
						{

							if (num_1[c] > num_2[c] || num_2[c] > num_1[c])
							{
								if (num_1[c] > num_2[c])
								{
									for (int i = num_1.size() - 1; i >= 0; i--)
									{
										string elem;
										vector<int>keepone;
										if (num_1[i] >= num_2[i])
										{
											razn[i] = num_1[i] - num_2[i];
										}
										else if (num_1[i] < num_2[i])
										{
											num_1[i] = num_1[i] + 10;
											i--;
											while (num_1[i] == 0)
											{
												num_1[i] = num_1[i] + 9;
												i--;
											}
											num_1[i] = num_1[i] - 1;
											i++;
											while (num_1[i] == 9)
											{
												i++;
											}
											razn[i] = num_1[i] - num_2[i];

										}
									}
									rez.push_back('-');
									if (razn[0] == 0)
									{
										vector<int>::iterator Era = razn.begin();
										razn.erase(Era);
									}
									for (int i = 0; i < razn.size(); i++)
									{
										el = to_string(razn[i]);
										for (int j = 0; j < el.size(); j++)
										{
											rez.push_back(el[j]);
										}
									}
									z.numb = rez;
									return z;
								}
								else
								{
									for (int i = num_2.size() - 1; i >= 0; i--)
									{
										string elem;
										vector<int>keepone;
										if (num_2[i] >= num_1[i])
										{
											razn[i] = num_2[i] - num_1[i];
										}
										else if (num_2[i] < num_1[i])
										{
											num_2[i] = num_2[i] + 10;
											i--;
											while (num_2[i] == 0)
											{
												num_2[i] = num_2[i] + 9;
												i--;
											}
											num_2[i] = num_2[i] - 1;
											i++;
											while (num_2[i] == 9)
											{
												i++;
											}
											razn[i] = num_2[i] - num_1[i];

										}
									}

									if (razn[0] == 0)
									{
										vector<int>::iterator Era = razn.begin();
										razn.erase(Era);
									}
									for (int i = 0; i < razn.size(); i++)
									{
										el = to_string(sum[i]);
										for (int j = 0; j < el.size(); j++)
										{
											rez.push_back(el[j]);
										}
									}
									z.numb = rez;
									return z;
								}
							}

						}
					}
				}
			}
			else 
			{
				if (a[0] == '-')
				{
					a = a.substr(1);
					for (int i = 0; i < a.size(); i++)
					{
						num_1.push_back(atoi(a.substr(i, 1).c_str()));
					}

					for (int j = 0; j < b.size(); j++)
					{
						num_2.push_back(atoi(b.substr(j, 1).c_str()));
					}
					if (num_1.size() >= num_2.size())
					{
						while (razn.size() != num_1.size())
						{
							razn.push_back(0);
						}
						while (num_1.size() != num_2.size())
						{
							vector<int>::iterator itIns = num_2.begin();
							num_2.insert(itIns, 0);
						}
						for (int k = num_1.size() - 1; k >= 0; k--)
						{
							string elem;
							vector<int>keepone;
							razn[k] = num_1[k] + num_2[k];

							if (razn[k] > 9)
							{
								if (k != 0)
								{
									elem = to_string(razn[k]);
									razn[k] = 0;
									razn[k] = atoi(elem.substr(1).c_str());
									keepone.push_back(atoi(elem.substr(0, 1).c_str()));
									k--;
									num_1[k] = num_1[k] + keepone[0];
									k++;
								}

							}

						}
						rez.push_back('-');
						for (int i = 0; i < razn.size(); i++)
						{
							el = to_string(razn[i]);
							for (int j = 0; j < el.size(); j++)
							{
								rez.push_back(el[j]);
							}
						}
						z.numb = rez;
						return z;
					}
					else if (num_2.size() > num_1.size())
					{
						while (razn.size() != num_2.size())
						{
							razn.push_back(0);
						}
						while (num_2.size() != num_1.size())
						{
							vector<int>::iterator itIns = num_1.begin();
							num_1.insert(itIns, 0);
						}

						for (int k = num_2.size() - 1; k >= 0; k--)
						{
							string elem;
							vector<int>keepone;
							razn[k] = num_2[k] + num_1[k];

							if (razn[k] > 9)
							{
								if (k != 0)
								{
									elem = to_string(razn[k]);
									razn[k] = 0;
									razn[k] = atoi(elem.substr(1).c_str());
									keepone.push_back(atoi(elem.substr(0, 1).c_str()));
									k--;
									num_2[k] = num_2[k] + keepone[0];
									k++;
								}

							}

						}
						rez.push_back('-');
						for (int i = 0; i < razn.size(); i++)
						{
							el = to_string(razn[i]);
							for (int j = 0; j < el.size(); j++)
							{
								rez.push_back(el[j]);
							}
						}
						z.numb = rez;
						return z;
					}
				}
				else
				{
					b = b.substr(1);
					for (int i = 0; i < a.size(); i++)
					{
						num_1.push_back(atoi(a.substr(i, 1).c_str()));
					}

					for (int j = 0; j < b.size(); j++)
					{
						num_2.push_back(atoi(b.substr(j, 1).c_str()));
					}
					if (num_1.size() >= num_2.size())
					{
						while (razn.size() != num_1.size())
						{
							razn.push_back(0);
						}
						while (num_1.size() != num_2.size())
						{
							vector<int>::iterator itIns = num_2.begin();
							num_2.insert(itIns, 0);
						}

						for (int k = num_1.size() - 1; k >= 0; k--)
						{
							string elem;
							vector<int>keepone;
							razn[k] = num_1[k] + num_2[k];

							if (razn[k] > 9)
							{
								if (k != 0)
								{
									elem = to_string(razn[k]);
									razn[k] = 0;
									razn[k] = atoi(elem.substr(1).c_str());
									keepone.push_back(atoi(elem.substr(0, 1).c_str()));
									k--;
									num_1[k] = num_1[k] + keepone[0];
									k++;
								}

							}

						}
						for (int i = 0; i < razn.size(); i++)
						{
							el = to_string(razn[i]);
							for (int j = 0; j < el.size(); j++)
							{
								rez.push_back(el[j]);
							}
						}
						z.numb = rez;
						return z;
					}
					else if (num_2.size() > num_1.size())
					{
						while (razn.size() != num_2.size())
						{
							razn.push_back(0);
						}
						while (num_2.size() != num_1.size())
						{
							vector<int>::iterator itIns = num_1.begin();
							num_1.insert(itIns, 0);
						}

						for (int k = num_2.size() - 1; k >= 0; k--)
						{
							string elem;
							vector<int>keepone;
							razn[k] = num_2[k] + num_1[k];

							if (razn[k] > 9)
							{
								if (k != 0)
								{
									elem = to_string(razn[k]);
									razn[k] = 0;
									razn[k] = atoi(elem.substr(1).c_str());
									keepone.push_back(atoi(elem.substr(0, 1).c_str()));
									k--;
									num_2[k] = num_2[k] + keepone[0];
									k++;
								}

							}

						}
						for (int i = 0; i < razn.size(); i++)
						{
							el = to_string(razn[i]);
							for (int j = 0; j < el.size(); j++)
							{
								rez.push_back(el[j]);
							}
						}
						z.numb = rez;
						return z;
					}
				}
			}

		}
		else if (a[0] != '-' && b[0] != '-')
		{
			for (int i = 0; i < a.size(); i++)
			{
				num_1.push_back(atoi(a.substr(i, 1).c_str()));
			}

			for (int j = 0; j < b.size(); j++)
			{
				num_2.push_back(atoi(b.substr(j, 1).c_str()));
			}
			if (num_1.size() >= num_2.size())
			{
				if (num_1.size() == num_2.size())
				{
					bool chek = num_1 == num_2;
					if (chek == 1)
					{
						z.numb = '0';
						return z;
					}
					else if (chek == 0)
					{
						for (int i = 0; i < num_1.size(); i++)
						{
							if (num_1[i] > num_2[i])
							{
								break;
							}
							else if (num_2[i] > num_1[i])
							{
								while (razn.size() != num_2.size())
								{
									razn.push_back(0);
								}
								for (int i = num_2.size() - 1; i >= 0; i--)
								{
									string elem;
									vector<int>keepone;
									if (num_2[i] >= num_1[i])
									{
										razn[i] = num_2[i] - num_1[i];
									}
									else if (num_2[i] < num_1[i])
									{
										num_2[i] = num_2[i] + 10;
										i--;
										while (num_2[i] == 0)
										{
											num_2[i] = num_2[i] + 9;
											i--;
										}
										num_2[i] = num_2[i] - 1;
										i++;
										while (num_2[i] == 9)
										{
											i++;
										}
										razn[i] = num_2[i] - num_1[i];

									}
								}
								rez.push_back('-');
								if (razn[0] == 0)
								{
									vector<int>::iterator Era = razn.begin();
									razn.erase(Era);
								}
								for (int i = 0; i < razn.size(); i++)
								{
									el = to_string(razn[i]);
									for (int j = 0; j < el.size(); j++)
									{
										rez.push_back(el[j]);
									}
								}
								z.numb = rez;
								return z;
							}
						}
					}
				}
				while (razn.size() != num_1.size())
				{
					razn.push_back(0);
				}
				while (num_1.size() != num_2.size())
				{
					vector<int>::iterator itIns = num_2.begin();
					num_2.insert(itIns, 0);
				}

				for (int i = num_1.size() - 1; i >= 0; i--)
				{
					string elem;
					vector<int>keepone;
					if (num_1[i] >= num_2[i])
					{
						razn[i] = num_1[i] - num_2[i];
					}
					else if (num_1[i] < num_2[i])
					{
						num_1[i] = num_1[i] + 10;
						i--;
						while (num_1[i] == 0)
						{
							num_1[i] = num_1[i] + 9;
							i--;
						}
						num_1[i] = num_1[i] - 1;
						i++;
						while (num_1[i] == 9)
						{
							i++;
						}
						razn[i] = num_1[i] - num_2[i];

					}
				}
				
				if (razn[0] == 0 && razn.size() != 1)
				{
					while (razn[0] == 0 && razn.size() != 1)
					{
						vector<int>::iterator Era = razn.begin();
						razn.erase(Era);
					}
				}
				for (int i = 0; i < razn.size(); i++)
				{
					el = to_string(razn[i]);
					for (int j = 0; j < el.size(); j++)
					{
						rez.push_back(el[j]);
					}
				}
				z.numb = rez;
				return z;
			}
			
			else if (num_2.size() > num_1.size())
			{
				while (razn.size() != num_2.size())
				{
					razn.push_back(0);
				}
				while (num_2.size() != num_1.size())
				{
					vector<int>::iterator itIns = num_1.begin();
					num_1.insert(itIns, 0);
				}
				for (int i = num_2.size() - 1; i >= 0; i--)
				{
					string elem;
					vector<int>keepone;
					if (num_2[i] >= num_1[i])
					{
						razn[i] = num_2[i] - num_1[i];
					}
					else if (num_2[i] < num_1[i])
					{
						num_2[i] = num_2[i] + 10;
						i--;
						while (num_2[i] == 0)
						{
							num_2[i] = num_2[i] + 9;
							i--;
						}
						num_2[i] = num_2[i] - 1;
						i++;
						while (num_2[i] == 9)
						{
							i++;
						}
						razn[i] = num_2[i] - num_1[i];

					}
				}
				rez.push_back('-');
				if (razn[0] == 0)
				{
					vector<int>::iterator Era = razn.begin();
					razn.erase(Era);
				}
				for (int i = 0; i < razn.size(); i++)
				{
					el = to_string(razn[i]);
					for (int j = 0; j < el.size(); j++)
					{
						rez.push_back(el[j]);
					}
				}
				z.numb = rez;
				return z;
			}
		}
		
	}
	BigNum operator * (BigNum num2)
	{
		BigNum z;
		int count = 1;
		string a = this->numb;
		string b = num2.numb;
		string el;
		string rez;
		string null;
		string min;
		vector<int> num_1;
		vector<int> num_2;
		vector<int> umn1;
		vector<int> check;
		
		for (int i = 0; i < a.size(); i++)
		{
			if (a[i] == '-' || a[i] == '0' || a[i] == '1' || a[i] == '2' || a[i] == '3' || a[i] == '4' || a[i] == '5' || a[i] == '6' ||
				a[i] == '7' || a[i] == '8' || a[i] == '9')
			{
				if (a[0] == '0'&&a.size() != 1)
				{
					cout << "The number entered is incorrect" << endl;
					return z;
				}
				else if (i != 0 && a[i] == '-')
				{
					cout << "The number entered is incorrect" << endl;
					return z;
				}
			}
			else
			{
				cout << "The number entered is incorrect" << endl;
				return z;
			}
		}
		for (int i = 0; i < b.size(); i++)
		{
			if (b[i] == '-' || b[i] == '0' || b[i] == '1' || b[i] == '2' || b[i] == '3' || b[i] == '4' || b[i] == '5' || b[i] == '6' ||
				b[i] == '7' || b[i] == '8' || b[i] == '9')
			{
				if (b[0] == '0' && b.size() != 1)
				{
					cout << "The number entered is incorrect" << endl;
					return z;
				}
				else if (i != 0 && b[i] == '-')
				{
					cout << "The number entered is incorrect" << endl;
					return z;
				}
			}
			else
			{
				cout << "The number entered is incorrect" << endl;
				return z;
			}
		}
		if (a[0] == '-'&&b[0] == '-')
		{
			a = a.substr(1);
			b = b.substr(1);
			min.push_back('-');
		}
		else if (a[0] == '-')
		{
			a = a.substr(1);
			min.push_back('-');
		}
		else if(b[0] == '-')
		{
			b = b.substr(1);
			min.push_back('-');
		}
		for (int i = 0; i < a.size(); i++)
		{
			num_1.push_back(atoi(a.substr(i, 1).c_str()));
		}
		while (num_1[num_1.size() - 1] == 0 && num_1.size()>1)
		{
			el = to_string(num_1[num_1.size() - 1]);	
			null.push_back(el[0]);	
			num_1.pop_back();
		}
		for (int j = 0; j < b.size(); j++)
		{
			num_2.push_back(atoi(b.substr(j, 1).c_str()));
		}
		while (num_2[num_2.size() - 1] == 0 && num_2.size() > 1)
		{
			el = to_string(num_2[num_2.size() - 1]);
			null.push_back(el[0]);
			num_2.pop_back();
		}
		if (num_1.size() >= num_2.size())
		{
			while (umn.size() != num_1.size())
			{
				umn.push_back(0);
			}
			if (num_2[0] == 0 && num_2.size() == 1)
			{
				
				z.numb = '0';
				return z;
			}
				
			for (int i = num_2.size() - 1; i >= 0; i--)
			{
				string elem;
				vector<int>keepone;
				vector<int> umn2;
					
					
				keepone.push_back(0);
				for (int j = num_1.size() - 1; j >= 0; j--)
				{
					umn[j] = keepone[0] + (num_1[j] * num_2[i]);
					keepone[0] = 0;
					if (umn[j] > 9)
					{
						if (j != 0)
						{
							elem = to_string(umn[j]);
							umn[j] = atoi(elem.substr(1).c_str());
							keepone[0]=atoi(elem.substr(0, 1).c_str());		
						}
							
					}
					if (num_2.size() > 1)
					{
						if (i == num_2.size() - 1)
						{
							if (j == num_1.size() - 1)
							{
								check.push_back(umn[j]);
								umn1.push_back(umn[j]);
							}
							else
							{
								vector<int>::iterator Ins = check.begin();
								check.insert(Ins, umn[j]);
								vector<int>::iterator In = umn1.begin();
								umn1.insert(In, check[0]);
							}
						}
						else
						{
							if (j == num_1.size() - 1)
							{
								umn2.push_back(umn[j]);
							}
							else
							{
								vector<int>::iterator ins = umn2.begin();

								umn2.insert(ins, umn[j]);
							}
						}

						if (j == 0 && i >= 0 && i < num_2.size() - 1)
						{

							if (umn1.size() == umn2.size())
							{
								vector<int>::iterator ins = umn1.begin();
								umn2.push_back(0);
								umn1.insert(ins, 0);
								for (int k = umn1.size() - 1; k >= 0; k--)
								{
									string elem;
									vector<int>keep;
									umn1[k] = umn1[k] + umn2[k];

									if (umn1[k] > 9)
									{
										if (k != 0)
										{
											elem = to_string(umn1[k]);

											umn1[k] = atoi(elem.substr(1).c_str());
											keep.push_back(atoi(elem.substr(0, 1).c_str()));
											k--;
											umn1[k] = umn1[k] + keep[0];
											k++;
										}

									}

								}
								count++;
							}
							else if (umn1.size() > umn2.size())
							{
								bool ch = check == umn1;
								if (ch == 1)
								{
									umn2.push_back(0);
									for (int k = umn1.size() - 1; k >= 0; k--)
									{
										string elem;
										vector<int>keep;
										umn1[k] = umn1[k] + umn2[k];

										if (umn1[k] > 9)
										{
											if (k != 0)
											{
												elem = to_string(umn1[k]);

												umn1[k] = atoi(elem.substr(1).c_str());
												keep.push_back(atoi(elem.substr(0, 1).c_str()));
												k--;
												umn1[k] = umn1[k] + keep[0];
												k++;
											}

										}

									}
									count++;
								}
								else if (ch == 0)
								{
									vector<int>::iterator ins = umn1.begin();
									umn1.insert(ins, 0);
									for (int n = count; ;)
									{
										for (int h = 0; h < n; h++)
										{
											umn2.push_back(0);
										}
										break;
									}
									count++;
									for (int k = umn1.size() - 1; k >= 0; k--)
									{
										string elem;
										vector<int>keep;
										umn1[k] = umn1[k] + umn2[k];

										if (umn1[k] > 9)
										{
											if (k != 0)
											{
												elem = to_string(umn1[k]);

												umn1[k] = atoi(elem.substr(1).c_str());
												keep.push_back(atoi(elem.substr(0, 1).c_str()));
												k--;
												umn1[k] = umn1[k] + keep[0];
												k++;
											}

										}

									}
								}
								if (i == 0)
								{
									if (min[0] == '-')
									{
										rez.push_back('-');
									}
									for (int i = 0; i < umn1.size(); i++)
									{
										el = to_string(umn1[i]);
										for (int j = 0; j < el.size(); j++)
										{
											rez.push_back(el[j]);
										}
									}
									if (null[0] == '0')
									{
										for (int j = 0; j < null.size(); j++)
										{
											rez.push_back(null[j]);
										}
									}
									z.numb = rez;
									return z;
								}
							}


						}
					}
					else
					{
						if (j == 0)
						{
							if (num_1[0] != 0 || num_2[0] != 0)
							{
								if (min[0] == '-')
								{
									rez.push_back('-');
								}
							}
							for (int i = 0; i < umn.size(); i++)
							{
								el = to_string(umn[i]);
								for (int j = 0; j < el.size(); j++)
								{
									rez.push_back(el[j]);
								}
							}
							if (null[0] == '0')
							{
								for (int j = 0; j < null.size(); j++)
								{
									rez.push_back(null[j]);
								}
							}

							z.numb = rez;
							return z;
						}
					}
				}

			}
			if (min[0] == '-')
			{
				rez.push_back('-');
			}
			for (int i = 0; i < umn1.size(); i++)
			{
				el = to_string(umn1[i]);
				for (int j = 0; j < el.size(); j++)
				{
					rez.push_back(el[j]);
				}
			}
			if (null[0] == '0')
			{
				for (int j = 0; j < null.size(); j++)
				{
					rez.push_back(null[j]);
				}
			}
			z.numb = rez;
			return z;
		}
		else if (num_2.size() > num_1.size())
		{
			while (umn.size() != num_2.size())
			{
				umn.push_back(0);
			}
			if (num_1[0] == 0 && num_1.size() == 1)
			{
				
				z.numb = '0';
				return z;
			}
				
			for (int i = num_1.size() - 1; i >= 0; i--)
			{
				string elem;
				vector<int>keepone;
				vector<int> umn2;
					
					
				keepone.push_back(0);
				for (int j = num_2.size() - 1; j >= 0; j--)
				{
					umn[j] = keepone[0] + (num_2[j] * num_1[i]);
					keepone[0] = 0;
					if (umn[j] > 9)
					{
						if (j != 0)
						{
							elem = to_string(umn[j]);
							umn[j] = atoi(elem.substr(1).c_str());
							keepone[0]=atoi(elem.substr(0, 1).c_str());		
						}
							
					}
					if (num_1.size() > 1)
					{
						if (i == num_1.size() - 1)
						{
							if (j == num_2.size() - 1)
							{
								check.push_back(umn[j]);
								umn1.push_back(umn[j]);
							}
							else
							{
								vector<int>::iterator Ins = check.begin();
								check.insert(Ins, umn[j]);
								vector<int>::iterator In = umn1.begin();
								umn1.insert(In, check[0]);
							}
						}
						else
						{
							if (j == num_2.size() - 1)
							{
								umn2.push_back(umn[j]);
							}
							else
							{
								vector<int>::iterator ins = umn2.begin();

								umn2.insert(ins, umn[j]);
							}
						}

						if (j == 0 && i >= 0 && i < num_1.size() - 1)
						{

							if (umn1.size() == umn2.size())
							{
								vector<int>::iterator ins = umn1.begin();
								umn2.push_back(0);
								umn1.insert(ins, 0);
								for (int k = umn1.size() - 1; k >= 0; k--)
								{
									string elem;
									vector<int>keep;
									umn1[k] = umn1[k] + umn2[k];

									if (umn1[k] > 9)
									{
										if (k != 0)
										{
											elem = to_string(umn1[k]);

											umn1[k] = atoi(elem.substr(1).c_str());
											keep.push_back(atoi(elem.substr(0, 1).c_str()));
											k--;
											umn1[k] = umn1[k] + keep[0];
											k++;
										}

									}

								}
								count++;
							}
							else if (umn1.size() > umn2.size())
							{
								bool ch = check == umn1;
								if (ch == 1)
								{
									umn2.push_back(0);
									for (int k = umn1.size() - 1; k >= 0; k--)
									{
										string elem;
										vector<int>keep;
										umn1[k] = umn1[k] + umn2[k];

										if (umn1[k] > 9)
										{
											if (k != 0)
											{
												elem = to_string(umn1[k]);

												umn1[k] = atoi(elem.substr(1).c_str());
												keep.push_back(atoi(elem.substr(0, 1).c_str()));
												k--;
												umn1[k] = umn1[k] + keep[0];
												k++;
											}

										}

									}
									count++;
								}
								else if (ch == 0)
								{
									vector<int>::iterator ins = umn1.begin();
									umn1.insert(ins, 0);
									for (int n = count; ;)
									{
										for (int h = 0; h < n; h++)
										{
											umn2.push_back(0);
										}
										break;
									}
									count++;
									for (int k = umn1.size() - 1; k >= 0; k--)
									{
										string elem;
										vector<int>keep;
										umn1[k] = umn1[k] + umn2[k];

										if (umn1[k] > 9)
										{
											if (k != 0)
											{
												elem = to_string(umn1[k]);

												umn1[k] = atoi(elem.substr(1).c_str());
												keep.push_back(atoi(elem.substr(0, 1).c_str()));
												k--;
												umn1[k] = umn1[k] + keep[0];
												k++;
											}

										}

									}
								}
								if (i == 0)
								{
									if (min[0] == '-')
									{
										rez.push_back('-');
									}
									for (int i = 0; i < umn1.size(); i++)
									{
										el = to_string(umn1[i]);
										for (int j = 0; j < el.size(); j++)
										{
											rez.push_back(el[j]);
										}
									}
									if (null[0] == '0')
									{
										for (int j = 0; j < null.size(); j++)
										{
											rez.push_back(null[j]);
										}
									}
									z.numb = rez;
									return z;
								}
							}


						}
					}
					else
					{
						if (j == 0)
						{
							if (num_2[0] != 0 || num_1[0] != 0)
							{
								if (min[0] == '-')
								{
									rez.push_back('-');
								}
							}
							for (int i = 0; i < umn.size(); i++)
							{
								el = to_string(umn[i]);
								for (int j = 0; j < el.size(); j++)
								{
									rez.push_back(el[j]);
								}
							}
							if (null[0] == '0')
							{
								for (int j = 0; j < null.size(); j++)
								{
									rez.push_back(null[j]);
								}
							}

							z.numb = rez;
							return z;
						}
					}
				}

			}
			if (min[0] == '-')
			{
				rez.push_back('-');
			}
			for (int i = 0; i < umn1.size(); i++)
			{
				el = to_string(umn1[i]);
				for (int j = 0; j < el.size(); j++)
				{
					rez.push_back(el[j]);
				}
			}
			if (null[0] == '0')
			{
				for (int j = 0; j < null.size(); j++)
				{
					rez.push_back(null[j]);
				}
			}
			z.numb = rez;
			return z;
		}
		
		return z;
	}
	BigNum operator / (BigNum num2)
	{
		BigNum z;
		string a = this->numb;
		string b = num2.numb;
		int count = 0;
		int counter = 1;
		int coun = 0;
		int keeper1;
		string el;
		string min;
		vector<int> num_1;
		vector<int> num_2;
		vector<int> del1;
		del1.push_back(0);
		vector<int> del2;
		del2.push_back(1);
		vector<int> check;

		for (int i = 0; i < a.size(); i++)
		{
			if (a[i] == '-' || a[i] == '0' || a[i] == '1' || a[i] == '2' || a[i] == '3' || a[i] == '4' || a[i] == '5' || a[i] == '6' ||
				a[i] == '7' || a[i] == '8' || a[i] == '9')
			{
				if (a[0] == '0'&&a.size() != 1)
				{
					cout << "The number entered is incorrect" << endl;
					return z;
				}
				else if (i != 0 && a[i] == '-')
				{
					cout << "The number entered is incorrect" << endl;
					return z;
				}
			}
			else
			{
				cout << "The number entered is incorrect" << endl;
				return z;
			}
		}
		for (int i = 0; i < b.size(); i++)
		{
			if (b[i] == '-' || b[i] == '0' || b[i] == '1' || b[i] == '2' || b[i] == '3' || b[i] == '4' || b[i] == '5' || b[i] == '6' ||
				b[i] == '7' || b[i] == '8' || b[i] == '9')
			{
				if (b[0] == '0' && b.size() != 1)
				{
					cout << "The number entered is incorrect" << endl;
					return z;
				}
				else if (i != 0 && b[i] == '-')
				{
					cout << "The number entered is incorrect" << endl;
					return z;
				}
			}
			else
			{
				cout << "The number entered is incorrect" << endl;
				return z;
			}
		}
		if (a[0] == '-'&&b[0] == '-')
		{
			a = a.substr(1);
			b = b.substr(1);
			min.push_back('-');
		}
		else if (a[0] == '-')
		{
			a = a.substr(1);
			min.push_back('-');
			z.numb.push_back('-');
		}
		else if (b[0] == '-')
		{
			b = b.substr(1);
			min.push_back('-');
			z.numb.push_back('-');
		}

		for (int i = 0; i < a.size(); i++)
		{
			num_1.push_back(atoi(a.substr(i, 1).c_str()));
		}
		for (int j = 0; j < b.size(); j++)
		{
			num_2.push_back(atoi(b.substr(j, 1).c_str()));
		}
		if (num_1[num_1.size() - 1] == 0 && num_2[num_2.size() - 1] == 0 && num_1.size() != 1 && num_2.size() != 1)
		{
			while (num_1[num_1.size() - 1] == 0 && num_2[num_2.size() - 1] == 0)
			{
				num_1.pop_back();
				num_2.pop_back();
			}
		}
		if (num_1.size() > num_2.size())
		{
			if (num_2[0] == 0)
			{
				if (z.numb[0] == '-')
				{
					z.numb.pop_back();
				}
				z.numb.push_back('0');
				return z;
			}
			for (int i = 0; i < num_1.size(); )
			{
				int mul = 0;
				if (counter > 1)
				{
					if (del.size() <= num_2.size())
					{
						del.push_back(num_1[i]);
						if (del[0] == 0)
						{
							z.numb.push_back('0');
							del.pop_back();
							if (i != num_1.size() - 1)
							{
								i++;
								continue;
							}
							else
							{
								return z;
							}
						}
						if (del.size() < num_2.size())
						{
							if (i == num_1.size() - 1)
							{
								z.numb.push_back('0');
								return z;
							}
							z.numb.push_back('0');
							i++;
							continue;
						}
					}
					else if (i == num_1.size() - 1)
					{
						return z;
					}
				}
				if (num_2.size() <= del.size())
				{
					coun = 0;
					
					bool chek = del == num_2;
					if (chek == 1)
					{
						
					}
					else if (chek == 0)
					{
						for (int c = 0; c < del.size(); c++)
						{
							
							if (del.size() > num_2.size())
							{
								break;
							}
							if (del[c] > num_2[c] || num_2[c] > del[c])
							{
								if (del[c] > num_2[c])
								{
									del1[0] = del[c];
									del2[0] = num_2[c];
								}
								else if(del[c] < num_2[c])
								{
									if (i != num_1.size() - 1)
									{
										if (counter > 1)
										{
											z.numb.push_back('0');

										}
										i++;
										del.push_back(num_1[i]);
										
									}
									else
									{
										z.numb.push_back('0');
										return z;
									}
								}
								break;
							}
						}
					}
					while (true)
					{
						mul++;
						check = num_2;
						while (num_2.size() != del.size())
						{
							vector<int>::iterator in = num_2.begin();
							num_2.insert(in, 0);
						}
						for (int j = del.size() - 1; j >= 0; j--)
						{
							string elem;
							vector<int>keepone;
							if (del[j] >= num_2[j])
							{
								del[j] = del[j] - num_2[j];
							}
							else if (del[j] < num_2[j])
							{
								del[j] = del[j] + 10;
								j--;
								while (del[j] == 0)
								{
									del[j] = del[j] + 9;
									j--;
								}
								del[j] = del[j] - 1;
								j++;
								while (del[j] == 9)
								{
									j++;
								}
								del[j] = del[j] - num_2[j];

							}
						}
						if (num_2 != check)
						{
							num_2 = check;
						}
						if (del[0] == 0 && del.size() != 1)
						{
							while (del.size() != 1)
							{
								vector<int>::iterator Era = del.begin();
								del.erase(Era);
								if (del[0] != 0)
								{
									break;
								}
							}
						}
						if (del.size() < num_2.size())
						{
							break;
						}
						if (del.size() == num_2.size())
						{
							for (int k = 0; k < del.size(); k++)
							{
								keeper1 = k;
								if (del[k] < num_2[k] || del[k]>num_2[k])
								{
									break;
								}

							}
						}
						if (del.size() == num_2.size())
						{
							if (del[keeper1] < num_2[keeper1])
							{
								break;
							}
						}
					}
					el = to_string(mul);
					z.numb.push_back(el[0]);
					if (del1[0] > del2[0])
					{
						if (i == num_1.size() - 1)
						{
							return z;
						}
					}
					if (del[0] == 0)
					{
						del.pop_back();
					}
					counter++;
					if (i != num_1.size() - 1)
					{
						i++;
					}
					else
					{
						return z;
					}
				}
				else
				{
					coun++;
				
					if (coun > 1)
					{
						if (i != num_1.size())
						{
							i++;
						}
					}
					del.push_back(num_1[i]);
					if (counter > 1)
					{
						if (del.size()<num_2.size())
						{
							if (i == num_1.size() - 1)
							{
								z.numb.push_back('0');
								return z;
							}
							z.numb.push_back('0');
						}

					}
					
					
				}
			}
		}
		else if (num_1.size() == num_2.size())
		{
			if (num_1[0] == 0 || num_2[0] == 0)
			{
				if (z.numb[0] == '-')
				{
					z.numb.pop_back();
				}
				z.numb = '0';
				return z;
			}
			bool chek = num_1 == num_2;
			if (chek == 1)
			{
				z.numb.push_back('1');
				return z;
			}
			for (int i = 0; i < num_1.size(); i++)
			{
				if (num_1[i] > num_2[i] || num_1[i] < num_2[i])
				{
					if (num_1[i] > num_2[i])
					{
						int mul = 0;
						while (true)
						{
							mul++;
							for (int j = num_1.size() - 1; j >= 0; j--)
							{
								string elem;
								vector<int>keepone;
								if (num_1[j] >= num_2[j])
								{
									num_1[j] = num_1[j] - num_2[j];
								}
								else if (num_1[j] < num_2[j])
								{
									num_1[j] = num_1[j] + 10;
									j--;
									while (num_1[j] == 0)
									{
										num_1[j] = num_1[j] + 9;
										j--;
									}
									num_1[j] = num_1[j] - 1;
									j++;
									while (num_1[j] == 9)
									{
										j++;
									}
									num_1[j] = num_1[j] - num_2[j];

								}
							}
							if (num_1[0] == 0 && num_1.size() != 1)
							{
								while (num_1.size() != 1)
								{
									vector<int>::iterator Era = num_1.begin();
									num_1.erase(Era);
									if (num_1[0] != 0)
									{
										break;
									}
								}
							}
							if (num_1.size() < num_2.size())
							{
								break;
							}
							if (num_1.size() == num_2.size())
							{
								for (int k = 0; k < num_1.size(); k++)
								{
									keeper1 = k;
									if (num_1[k] < num_2[k] || num_1[k]>num_2[k])
									{
										break;
									}

								}
							}
							if (num_1.size() == num_2.size())
							{
								if (num_1[keeper1] < num_2[keeper1])
								{
									break;
								}
							}
						}
						el = to_string(mul);
						z.numb.push_back(el[0]);
						return z;
					}
					else if(num_1[i] < num_2[i])
					{
						if (z.numb[0] == '-')
						{
							z.numb.pop_back();
						}
						z.numb = '0';
						return z;
					}
				}

			}
			
		}
		else if (num_1.size() < num_2.size())
		{
			if (z.numb[0] == '-')
			{
				z.numb.pop_back();
			}
			z.numb = '0';
			return z;
		}
		
	}

	void time_test(BigNum a, BigNum b) 
	{
		clock_t time_start;
		clock_t time_end;
		double t;
		time_start = clock();
		a + b;
		time_end = clock();
		t = (double)(time_end - time_start) / CLOCKS_PER_SEC;
		cout << "time sum : " << t << endl;
		
		time_start = clock();
		a - b;
		time_end = clock();
		t = (double)(time_end - time_start) / CLOCKS_PER_SEC;
		cout << "time Razn : " << t << endl;
		
		time_start = clock();
		a * b;
		time_end = clock();
		t = (double)(time_end - time_start) / CLOCKS_PER_SEC;
		cout << "time Umn : " << t << endl;
		
		time_start = clock();
		a / b;
		time_end = clock();
		t = (double)(time_end - time_start) / CLOCKS_PER_SEC;
		cout << "time Del : " << t << endl;
		
	}
	
	
};

int main()
{
	while (true)
	{
		BigNum a;
		BigNum b;

		cout << "Enter numbers:" << endl;
		cin >> a;
		cin >> b;
		a.time_test(a, b);
		cout << endl;
		cout << "Sum:" << " " << a + b << endl;
		cout << "Razn:" << " " << a - b << endl;
		cout << "Umn:" << " " << a * b << endl;
		cout << "Del:" << " " << a / b << endl;
		
		cout << endl;
	}
	system("pause");
	return 0;
}

