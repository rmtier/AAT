/**
* author: Rami Mtier
* date: 10.9.2016
*/

namespace AAT
{
	class AatCore
	{
	public:
		/**
		* @brief Run library
		*/
		void Run();

		/**
		* @brief Get progress
		* @return the percentage of progress while processsing
		*/
		double GetProgress();

		/**
		* @brief init
		*/
		void Init();
	};
}
