/************************************************************************************
TerraView - visualization and exploration of geographical databases
using TerraLib.
Copyright � 2001-2007 INPE and Tecgraf/PUC-Rio.
This file is part of TerraView. TerraView is free software; you can redistribute it 
and/or modify it under the terms of the GNU General Public License as published by
the Free Software Foundation; either version 2 of the License, or
(at your option) any later version.

You should have received a copy of the GNU General Public License
along with TerraView.
The authors reassure the license terms regarding the warranties.
They specifically disclaim any warranties, including, but not limited to,
the implied warranties of merchantability and fitness for a particular purpose.
The software provided hereunder is on an "as is" basis, and the authors have no
obligation to provide maintenance, support, updates, enhancements, or modifications.
In no event shall INPE and Tecgraf / PUC-Rio be held liable to any party for direct,
indirect, special, incidental, or consequential damages arising out of the use of
this program and its documentation.
*************************************************************************************/

#include <qpixmap.h>
#include <TeQtDatabaseItem.h>
#include <images/database.xpm>


//Database item constructor
TeQtDatabaseItem::TeQtDatabaseItem(QListView *parent,
	QString text, TeDatabase *db)
	: TeQtCheckListItem(parent,text), db_(db)
{
	type_ = DATABASE;
	QPixmap p(database_xpm);
	setPixmap(0,p);
	sortChildItems(0, true);
	setSelected(false);
	setEnabled(true);
}

				
