/******************************************************************************
 *
 * Module Name: dtcompiler.h - header for data table compiler
 *
 *****************************************************************************/

/*
 * Copyright (C) 2000 - 2021, Intel Corp.
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions
 * are met:
 * 1. Redistributions of source code must retain the above copyright
 *    notice, this list of conditions, and the following disclaimer,
 *    without modification.
 * 2. Redistributions in binary form must reproduce at minimum a disclaimer
 *    substantially similar to the "NO WARRANTY" disclaimer below
 *    ("Disclaimer") and any redistribution must be conditioned upon
 *    including a substantially similar Disclaimer requirement for further
 *    binary redistribution.
 * 3. Neither the names of the above-listed copyright holders nor the names
 *    of any contributors may be used to endorse or promote products derived
 *    from this software without specific prior written permission.
 *
 * Alternatively, this software may be distributed under the terms of the
 * GNU General Public License ("GPL") version 2 as published by the Free
 * Software Foundation.
 *
 * NO WARRANTY
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS
 * "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT
 * LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR
 * A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT
 * HOLDERS OR CONTRIBUTORS BE LIABLE FOR SPECIAL, EXEMPLARY, OR CONSEQUENTIAL
 * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS
 * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)
 * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT,
 * STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING
 * IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE
 * POSSIBILITY OF SUCH DAMAGES.
 */

#define __DTCOMPILER_H__

#ifndef _DTCOMPILER
#define _DTCOMPILER

#include "acdisasm.h"


#define ASL_FIELD_CACHE_SIZE            512
#define ASL_SUBTABLE_CACHE_SIZE         128


#undef DT_EXTERN

#ifdef _DECLARE_DT_GLOBALS
#define DT_EXTERN
#define DT_INIT_GLOBAL(a,b)         (a)=(b)
#else
#define DT_EXTERN                   extern
#define DT_INIT_GLOBAL(a,b)         (a)
#endif


/* Types for individual fields (one per input line) */

#define DT_FIELD_TYPE_STRING            0
#define DT_FIELD_TYPE_INTEGER           1
#define DT_FIELD_TYPE_BUFFER            2
#define DT_FIELD_TYPE_PCI_PATH          3
#define DT_FIELD_TYPE_FLAG              4
#define DT_FIELD_TYPE_FLAGS_INTEGER     5
#define DT_FIELD_TYPE_INLINE_SUBTABLE   6
#define DT_FIELD_TYPE_UUID              7
#define DT_FIELD_TYPE_UNICODE           8
#define DT_FIELD_TYPE_DEVICE_PATH       9
#define DT_FIELD_TYPE_LABEL             10


/*
 * Structure used for each individual field within an ACPI table
 */
typedef struct dt_field
{
    char                    *Name;       /* Field name (from name : value) */
    char                    *Value;      /* Field value (from name : value) */
    UINT32                  StringLength; /* Length of Value */
    struct dt_field         *Next;       /* Next field */
    struct dt_field         *NextLabel;  /* If field is a label, next label */
    UINT32                  Line;        /* Line number for this field */
    UINT32                  ByteOffset;  /* Offset in source file for field */
    UINT32                  NameColumn;  /* Start column for field name */
    UINT32                  Column;      /* Start column for field value */
    UINT32                  TableOffset; /* Binary offset within ACPI table */
    UINT8                   Flags;

} DT_FIELD;

/* Flags for above */

#define DT_FIELD_NOT_ALLOCATED      1

/*
 * Structure used for each individual key or value
 */
typedef struct dt_table_unit
{
    char                    *Value;      /* Field value (from name : value) */
    UINT32                  Line;        /* Line number for this field */
    UINT32                  Column;      /* Start column for field value */

} DT_TABLE_UNIT;


/*
 * Structure used for individual subtables within an ACPI table
 */
typedef struct dt_subtable
{
    struct dt_subtable      *Parent;
    struct dt_subtable      *Child;
    struct dt_subtable      *Peer;
    struct dt_subtable      *StackTop;
    UINT8                   *Buffer;
    UINT8                   *LengthField;
    char                    *Name;
    UINT32                  Length;
    UINT32                  TotalLength;
    UINT32                  SizeOfLengthField;
    UINT16                  Depth;
    UINT8                   Flags;

} DT_SUBTABLE;


/*
 * Globals
 */

/* List of all field names and values from the input source */

DT_EXTERN DT_FIELD          DT_INIT_GLOBAL (*AslGbl_FieldList, NULL);

/* List of all compiled tables and subtables */

DT_EXTERN DT_SUBTABLE       DT_INIT_GLOBAL (*AslGbl_RootTable, NULL);

/* Stack for subtables */

DT_EXTERN DT_SUBTABLE       DT_INIT_GLOBAL (*AslGbl_SubtableStack, NULL);

/* List for defined labels */

DT_EXTERN DT_FIELD          DT_INIT_GLOBAL (*AslGbl_LabelList, NULL);

/* Current offset within the binary output table */

DT_EXTERN UINT32            DT_INIT_GLOBAL (AslGbl_CurrentTableOffset, 0);

/* Data table compiler Flex/Bison prototype */

DT_EXTERN BOOLEAN           DT_INIT_GLOBAL (AslGbl_DtLexBisonPrototype, FALSE);

/* Local caches */

DT_EXTERN UINT32            DT_INIT_GLOBAL (AslGbl_SubtableCount, 0);
DT_EXTERN ASL_CACHE_INFO    DT_INIT_GLOBAL (*AslGbl_SubtableCacheList, NULL);
DT_EXTERN DT_SUBTABLE       DT_INIT_GLOBAL (*AslGbl_SubtableCacheNext, NULL);
DT_EXTERN DT_SUBTABLE       DT_INIT_GLOBAL (*AslGbl_SubtableCacheLast, NULL);

DT_EXTERN UINT32            DT_INIT_GLOBAL (AslGbl_FieldCount, 0);
DT_EXTERN ASL_CACHE_INFO    DT_INIT_GLOBAL (*AslGbl_FieldCacheList, NULL);
DT_EXTERN DT_FIELD          DT_INIT_GLOBAL (*AslGbl_FieldCacheNext, NULL);
DT_EXTERN DT_FIELD          DT_INIT_GLOBAL (*AslGbl_FieldCacheLast, NULL);


/* dtcompiler - main module */

ACPI_STATUS
DtCompileTable (
    DT_FIELD                **Field,
    ACPI_DMTABLE_INFO       *Info,
    DT_SUBTABLE             **RetSubtable);

ACPI_STATUS
DtCompileTwoSubtables (
    void                    **List,
    ACPI_DMTABLE_INFO       *TableInfo1,
    ACPI_DMTABLE_INFO       *TableInfo2);

ACPI_STATUS
DtCompilePadding (
    UINT32                  Length,
    DT_SUBTABLE             **RetSubtable);


/* dtio - binary and text input/output */

UINT32
DtGetNextLine (
    FILE                    *Handle,
    UINT32                  Flags);

/* Flags for DtGetNextLine */

#define DT_ALLOW_MULTILINE_QUOTES   0x01


DT_FIELD *
DtScanFile (
    FILE                    *Handle);

void
DtOutputBinary (
    DT_SUBTABLE             *RootTable);

void
DtDumpSubtableList (
    void);

void
DtDumpFieldList (
    DT_FIELD                *Field);

void
DtWriteFieldToListing (
    UINT8                   *Buffer,
    DT_FIELD                *Field,
    UINT32                  Length);

void
DtWriteTableToListing (
    void);


/* dtsubtable - compile subtables */

void
DtCreateSubtable (
    UINT8                   *Buffer,
    UINT32                  Length,
    DT_SUBTABLE             **RetSubtable);

UINT32
DtGetSubtableLength (
    DT_FIELD                *Field,
    ACPI_DMTABLE_INFO       *Info);

void
DtSetSubtableLength (
    DT_SUBTABLE             *Subtable);

void
DtPushSubtable (
    DT_SUBTABLE             *Subtable);

void
DtPopSubtable (
    void);

DT_SUBTABLE *
DtPeekSubtable (
    void);

void
DtInsertSubtable (
    DT_SUBTABLE             *ParentTable,
    DT_SUBTABLE             *Subtable);

DT_SUBTABLE *
DtGetNextSubtable (
    DT_SUBTABLE             *ParentTable,
    DT_SUBTABLE             *ChildTable);

DT_SUBTABLE *
DtGetParentSubtable (
    DT_SUBTABLE             *Subtable);


/* dtexpress - Integer expressions and labels */

ACPI_STATUS
DtResolveIntegerExpression (
    DT_FIELD                *Field,
    UINT64                  *ReturnValue);

UINT64
DtDoOperator (
    UINT64                  LeftValue,
    UINT32                  Operator,
    UINT64                  RightValue);

UINT64
DtResolveLabel (
    char                    *LabelString);

void
DtDetectAllLabels (
    DT_FIELD                *FieldList);


/* dtfield - Compile individual fields within a table */

void
DtCompileOneField (
    UINT8                   *Buffer,
    DT_FIELD                *Field,
    UINT32                  ByteLength,
    UINT8                   Type,
    UINT8                   Flags);

void
DtCompileInteger (
    UINT8                   *Buffer,
    DT_FIELD                *Field,
    UINT32                  ByteLength,
    UINT8                   Flags);

UINT32
DtCompileBuffer (
    UINT8                   *Buffer,
    char                    *Value,
    DT_FIELD                *Field,
    UINT32                  ByteLength);

void
DtCompileFlag (
    UINT8                   *Buffer,
    DT_FIELD                *Field,
    ACPI_DMTABLE_INFO       *Info);


/* dtfield - DT_FIELD operations */

void
DtLinkField (
    DT_FIELD                *Field);

void
DtCreateField (
    DT_TABLE_UNIT           *FieldKey,
    DT_TABLE_UNIT           *FieldValue,
    UINT32                  Offset);

DT_TABLE_UNIT *
DtCreateTableUnit (
    char                    *Data,
    UINT32                  Line,
    UINT32                  Column);


/* dtparser - lex/yacc files */

int
DtCompilerParserparse (
    void);

UINT64
DtEvaluateExpression (
    char                    *ExprString);

void
DtCompilerInitLexer (
    FILE                    *inFile);

void
DtCompilerTerminateLexer (
    void);

int
DtInitLexer (
    char                    *String);

void
DtTerminateLexer (
    void);

char *
DtGetOpName (
    UINT32                  ParseOpcode);


/* dtutils - Miscellaneous utilities */

typedef
void (*DT_WALK_CALLBACK) (
    DT_SUBTABLE             *Subtable,
    void                    *Context,
    void                    *ReturnValue);

void
DtWalkTableTree (
    DT_SUBTABLE             *StartTable,
    DT_WALK_CALLBACK        UserFunction,
    void                    *Context,
    void                    *ReturnValue);

void
DtError (
    UINT8                   Level,
    UINT16                  MessageId,
    DT_FIELD                *FieldObject,
    char                    *ExtraMessage);

void
DtNameError (
    UINT8                   Level,
    UINT16                  MessageId,
    DT_FIELD                *FieldObject,
    char                    *ExtraMessage);

void
DtFatal (
    UINT16                  MessageId,
    DT_FIELD                *FieldObject,
    char                    *ExtraMessage);

UINT64
DtDoConstant (
    char                    *String);

char*
DtGetFieldValue (
    DT_FIELD                *Field);

UINT8
DtGetFieldType (
    ACPI_DMTABLE_INFO       *Info);

UINT32
DtGetBufferLength (
    char                    *Buffer);

UINT32
DtGetFieldLength (
    DT_FIELD                *Field,
    ACPI_DMTABLE_INFO       *Info);

void
DtSetTableChecksum (
    UINT8                   *ChecksumPointer);

void
DtSetTableLength(
    void);


/* dttable - individual table compilation */

ACPI_STATUS
DtCompileFacs (
    DT_FIELD                **PFieldList);

ACPI_STATUS
DtCompileRsdp (
    DT_FIELD                **PFieldList);

ACPI_STATUS
DtCompileAest (
    void                    **PFieldList);

ACPI_STATUS
DtCompileAsf (
    void                    **PFieldList);

ACPI_STATUS
DtCompileCpep (
    void                    **PFieldList);

ACPI_STATUS
DtCompileCedt (
    void                    **PFieldList);

ACPI_STATUS
DtCompileCsrt (
    void                    **PFieldList);

ACPI_STATUS
DtCompileDbg2 (
    void                    **PFieldList);

ACPI_STATUS
DtCompileDmar (
    void                    **PFieldList);

ACPI_STATUS
DtCompileDrtm (
    void                    **PFieldList);

ACPI_STATUS
DtCompileEinj (
    void                    **PFieldList);

ACPI_STATUS
DtCompileErst (
    void                    **PFieldList);

ACPI_STATUS
DtCompileFadt (
    void                    **PFieldList);

ACPI_STATUS
DtCompileFpdt (
    void                    **PFieldList);

ACPI_STATUS
DtCompileGtdt (
    void                    **PFieldList);

ACPI_STATUS
DtCompileHest (
    void                    **PFieldList);

ACPI_STATUS
DtCompileHmat (
    void                    **PFieldList);

ACPI_STATUS
DtCompileIort (
    void                    **PFieldList);

ACPI_STATUS
DtCompileIvrs (
    void                    **PFieldList);

ACPI_STATUS
DtCompileLpit (
    void                    **PFieldList);

ACPI_STATUS
DtCompileMadt (
    void                    **PFieldList);

ACPI_STATUS
DtCompileMcfg (
    void                    **PFieldList);

ACPI_STATUS
DtCompileMpst (
    void                    **PFieldList);

ACPI_STATUS
DtCompileMsct (
    void                    **PFieldList);

ACPI_STATUS
DtCompileNfit (
    void                    **PFieldList);

ACPI_STATUS
DtCompileNhlt (
    void                    **PFieldList);

ACPI_STATUS
DtCompilePcct (
    void                    **PFieldList);

ACPI_STATUS
DtCompilePdtt (
    void                    **PFieldList);

ACPI_STATUS
DtCompilePhat (
    void                    **PFieldList);

ACPI_STATUS
DtCompilePmtt (
    void                    **PFieldList);

ACPI_STATUS
DtCompilePptt (
    void                    **PFieldList);

ACPI_STATUS
DtCompilePrmt (
    void                    **PFieldList);

ACPI_STATUS
DtCompileRgrt (
    void                    **PFieldList);

ACPI_STATUS
DtCompileRsdt (
    void                    **PFieldList);

ACPI_STATUS
DtCompileS3pt (
    DT_FIELD                **PFieldList);

ACPI_STATUS
DtCompileSdev (
    void                    **PFieldList);

ACPI_STATUS
DtCompileSlic (
    void                    **PFieldList);

ACPI_STATUS
DtCompileSlit (
    void                    **PFieldList);

ACPI_STATUS
DtCompileSrat (
    void                    **PFieldList);

ACPI_STATUS
DtCompileStao (
    void                    **PFieldList);

ACPI_STATUS
DtCompileSvkl (
    void                    **PFieldList);

ACPI_STATUS
DtCompileTcpa (
    void                    **PFieldList);

ACPI_STATUS
DtCompileTpm2 (
    void                    **PFieldList);

ACPI_STATUS
DtCompileUefi (
    void                    **PFieldList);

ACPI_STATUS
DtCompileViot (
    void                    **PFieldList);

ACPI_STATUS
DtCompileWdat (
    void                    **PFieldList);

ACPI_STATUS
DtCompileWpbt (
    void                    **PFieldList);

ACPI_STATUS
DtCompileXsdt (
    void                    **PFieldList);

ACPI_STATUS
DtCompileGeneric (
    void                    **PFieldList,
    char                    *TermFieldName,
    UINT32                  *PFieldLength);

ACPI_DMTABLE_INFO *
DtGetGenericTableInfo (
    char                    *Name);

/* ACPI Table templates */

extern const unsigned char  TemplateAest[];
extern const unsigned char  TemplateAsf[];
extern const unsigned char  TemplateBoot[];
extern const unsigned char  TemplateBdat[];
extern const unsigned char  TemplateBert[];
extern const unsigned char  TemplateBgrt[];
extern const unsigned char  TemplateCedt[];
extern const unsigned char  TemplateCpep[];
extern const unsigned char  TemplateCsrt[];
extern const unsigned char  TemplateDbg2[];
extern const unsigned char  TemplateDbgp[];
extern const unsigned char  TemplateDmar[];
extern const unsigned char  TemplateDrtm[];
extern const unsigned char  TemplateEcdt[];
extern const unsigned char  TemplateEinj[];
extern const unsigned char  TemplateErst[];
extern const unsigned char  TemplateFadt[];
extern const unsigned char  TemplateFpdt[];
extern const unsigned char  TemplateGtdt[];
extern const unsigned char  TemplateHest[];
extern const unsigned char  TemplateHmat[];
extern const unsigned char  TemplateHpet[];
extern const unsigned char  TemplateIort[];
extern const unsigned char  TemplateIvrs[];
extern const unsigned char  TemplateLpit[];
extern const unsigned char  TemplateMadt[];
extern const unsigned char  TemplateMcfg[];
extern const unsigned char  TemplateMchi[];
extern const unsigned char  TemplateMpst[];
extern const unsigned char  TemplateMsct[];
extern const unsigned char  TemplateMsdm[];
extern const unsigned char  TemplateNfit[];
extern const unsigned char  TemplatePcct[];
extern const unsigned char  TemplatePdtt[];
extern const unsigned char  TemplatePhat[];
extern const unsigned char  TemplatePmtt[];
extern const unsigned char  TemplatePptt[];
extern const unsigned char  TemplatePrmt[];
extern const unsigned char  TemplateRasf[];
extern const unsigned char  TemplateRgrt[];
extern const unsigned char  TemplateRsdt[];
extern const unsigned char  TemplateS3pt[];
extern const unsigned char  TemplateSbst[];
extern const unsigned char  TemplateSdei[];
extern const unsigned char  TemplateSdev[];
extern const unsigned char  TemplateSlic[];
extern const unsigned char  TemplateSlit[];
extern const unsigned char  TemplateSpcr[];
extern const unsigned char  TemplateSpmi[];
extern const unsigned char  TemplateSrat[];
extern const unsigned char  TemplateStao[];
extern const unsigned char  TemplateSvkl[];
extern const unsigned char  TemplateTcpa[];
extern const unsigned char  TemplateTpm2[];
extern const unsigned char  TemplateUefi[];
extern const unsigned char  TemplateViot[];
extern const unsigned char  TemplateWaet[];
extern const unsigned char  TemplateWdat[];
extern const unsigned char  TemplateWddt[];
extern const unsigned char  TemplateWdrt[];
extern const unsigned char  TemplateWpbt[];
extern const unsigned char  TemplateWsmt[];
extern const unsigned char  TemplateXenv[];
extern const unsigned char  TemplateXsdt[];

#endif
