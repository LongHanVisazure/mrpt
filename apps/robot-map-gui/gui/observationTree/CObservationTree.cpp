/* +---------------------------------------------------------------------------+
   |                     Mobile Robot Programming Toolkit (MRPT)               |
   |                          http://www.mrpt.org/                             |
   |                                                                           |
   | Copyright (c) 2005-2017, Individual contributors, see AUTHORS file        |
   | See: http://www.mrpt.org/Authors - All rights reserved.                   |
   | Released under BSD License. See details in http://www.mrpt.org/License    |
   +---------------------------------------------------------------------------+
   */
#include "CObservationTree.h"
#include "CObservationTreeModel.h"
#include "CNode.h"

#include <QContextMenuEvent>
#include <QMenu>

CObservationTree::CObservationTree(QWidget* parent)
	: QTreeView(parent), m_model(nullptr)
{
}

void CObservationTree::setModel(QAbstractItemModel* model)
{
	m_model = dynamic_cast<CObservationTreeModel*>(model);
	QTreeView::setModel(model);
}

void CObservationTree::expandAll()
{
	if (!m_model) return;

	QModelIndexList indexes = m_model->match(
		m_model->index(0, 0, QModelIndex()), Qt::DisplayRole, "*", -1,
		Qt::MatchWildcard | Qt::MatchRecursive);
	foreach (QModelIndex index, indexes)
		expand(index);
}

void CObservationTree::collapseAll()
{
	if (!m_model) return;

	QModelIndexList indexes = m_model->match(
		m_model->index(0, 0, QModelIndex()), Qt::DisplayRole, "*", -1,
		Qt::MatchWildcard | Qt::MatchRecursive);
	foreach (QModelIndex index, indexes)
		collapse(index);
}

void CObservationTree::contextMenuEvent(QContextMenuEvent* event)
{
	if (m_model)
	{
		QModelIndex index = indexAt(event->pos());
		CNode* node = m_model->getNode(index);
		if (node)
		{
			QMenu menu(this);
			menu.exec(event->globalPos());
		}
	}
	QWidget::contextMenuEvent(event);
}
