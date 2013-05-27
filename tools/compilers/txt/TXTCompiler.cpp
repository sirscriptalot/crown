/*
Copyright (c) 2012 Daniele Bartolini, Simone Boscaratto

Permission is hereby granted, free of charge, to any person
obtaining a copy of this software and associated documentation
files (the "Software"), to deal in the Software without
restriction, including without limitation the rights to use,
copy, modify, merge, publish, distribute, sublicense, and/or sell
copies of the Software, and to permit persons to whom the
Software is furnished to do so, subject to the following
conditions:

The above copyright notice and this permission notice shall be
included in all copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND,
EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES
OF MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND
NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT
HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY,
WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING
FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR
OTHER DEALINGS IN THE SOFTWARE.
*/

#include "TXTCompiler.h"
#include "DiskFile.h"
#include "Resource.h"

namespace crown
{

//-----------------------------------------------------------------------------
TXTCompiler::TXTCompiler(const char* root_path, const char* dest_path) :
	Compiler(root_path, dest_path, TEXT_TYPE),
	m_file_size(0),
	m_file_data(NULL)
{
}

//-----------------------------------------------------------------------------
TXTCompiler::~TXTCompiler()
{
	cleanup_impl();
}

//-----------------------------------------------------------------------------
size_t TXTCompiler::read_header_impl(DiskFile* in_file)
{
	(void) in_file;
	return 0;
}

//-----------------------------------------------------------------------------
size_t TXTCompiler::read_resource_impl(DiskFile* in_file)
{
	m_file_size = in_file->size();

	m_file_data = new char[m_file_size];
	
	// Copy the entire file into the buffer
	in_file->read(m_file_data, m_file_size);

	// Return the total resource size
	return m_file_size + sizeof(uint32_t);
}

//-----------------------------------------------------------------------------
void TXTCompiler::write_header_impl(DiskFile* out_file)
{
	out_file->write(&m_file_size, sizeof(uint32_t));
}

//-----------------------------------------------------------------------------
void TXTCompiler::write_resource_impl(DiskFile* out_file)
{
	out_file->write(m_file_data, m_file_size);
}

void TXTCompiler::cleanup_impl()
{
	if (m_file_data)
	{
		delete[] m_file_data;
		m_file_data = NULL;
	}
}

} // namespace crown
