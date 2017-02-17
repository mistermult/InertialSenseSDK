/*
MIT LICENSE

Copyright 2014 Inertial Sense, LLC - http://inertialsense.com

Permission is hereby granted, free of charge, to any person obtaining a copy of this software and associated documentation files(the "Software"), to deal in the Software without restriction, including without limitation the rights to use, copy, modify, merge, publish, distribute, sublicense, and/or sell copies of the Software, and to permit persons to whom the Software is furnished to do so, subject to the following conditions :

The above copyright notice and this permission notice shall be included in all copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT.IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.
*/

#ifndef __ISTCPCLIENT__H__
#define __ISTCPCLIENT__H__

#include <string>
#include <inttypes.h>

using namespace std;

class ISTcpClient
{
public:
	/*!
	* Constructor
	*/
	ISTcpClient();

	/*!
	* Destructor
	*/
	virtual ~ISTcpClient();

	/*!
	* Closes, then opens a tcp client
	* @param host the host or ip address to connect to
	* @param port the port to connect to on the host
	* @return 0 if success, otherwise an error code
	*/
	int Open(const string& host, int port);

	/*!
	* Close the client
	* @return 0 if success, otherwise an error code
	*/
	int Close();

	/*!
	* Read data from the client
	* @param data the buffer to read data into
	* @param dataLength the number of bytes available in data
	* @param blocking whether to block or timeout until data is received, if false method returns immediately with number of bytes read
	* @return the number of bytes read or less than 0 if error
	*/
	int Read(uint8_t* data, int dataLength, bool blocking = true);

	/*!
	* Write data to the client
	* @param data the data to write
	* @param dataLength the number of bytes to write
	* @return the number of bytes written or less than 0 if error
	*/
	int Write(uint8_t* data, int dataLength);

	/*!
	* Get whether the connection is open
	* @return true if connection open, false if not
	*/
	bool IsOpen() { return m_socket != 0; }

private:
	uint64_t m_socket;
	string m_host;
	int m_port;
};

#endif // __ISTCPCLIENT__H__
