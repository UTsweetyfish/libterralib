/************************************************************************************
TerraLib - a library for developing GIS applications.
Copyright � 2001-2007 INPE and Tecgraf/PUC-Rio.

This code is part of the TerraLib library.
This library is free software; you can redistribute it and/or
modify it under the terms of the GNU Lesser General Public
License as published by the Free Software Foundation; either
version 2.1 of the License, or (at your option) any later version.

You should have received a copy of the GNU Lesser General Public
License along with this library.

The authors reassure the license terms regarding the warranties.
They specifically disclaim any warranties, including, but not limited to,
the implied warranties of merchantability and fitness for a particular purpose.
The library provided hereunder is on an "as is" basis, and the authors have no
obligation to provide maintenance, support, updates, enhancements, or modifications.
In no event shall INPE and Tecgraf / PUC-Rio be held liable to any party for direct,
indirect, special, incidental, or consequential damages arising out of the use
of this library and its documentation.
*************************************************************************************/

#ifdef WIN32
#pragma warning ( disable: 4786 )
#endif

#include "TeStdFile.h"
#include "TeException.h"



// -- Constructor

TeStdFile::TeStdFile ( const string& name, const char* mode ):
	file_ ( 0 ), fileName_ ( name ), mode_ ( mode )
{
	const char* inputFile = fileName_.c_str();
	if ( name.size() <= 1 )
		throw TeException ( EMPTY_FILE_NAME, name, false );
	
	if ( ( file_ = fopen( inputFile, mode ) ) == 0 )
	{
		bool hasErrno = true;
		throw TeException ( CANNOT_OPEN_FILE, name, hasErrno );
	}
}

TeStdFile::~TeStdFile() 
{ 
	if(file_ ) 
		fclose(file_);
}

void
TeStdFile::rewind()
{
	if (file_)
		fseek(file_,0,0);
}
